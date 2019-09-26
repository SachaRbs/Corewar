/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:56:05 by sarobber          #+#    #+#             */
/*   Updated: 2019/09/26 12:37:30 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void   pushfront_proc(t_proc **head, t_proc *new)
{
    if (head && *head && new)
    {
        new->next = *head;
        *head = new;
    }
    else
        *head = new;
}
void    parsing(t_vm *vm, int ac, char **av)
{
	int i;

	i = 0;
	vm->pnum[vm->pct] = -1;
	while (++i < ac)
	{
		if (av[i][0] == '-' )
		{
			if (av[i][1] == 'n' && !av[i][2] && ac > ++i) {
				vm->pnum[vm->pct] = ft_atoi(av[i]); // atoi qui check si le numero de -n 'X' est bon ( < MAX_PLAYERS)
				vm->play_free[vm->pnum[vm->pct]] = 1;
			}
			else if (av[i][1] == 'd')
				vm->dump = ft_atoi(av[i]);
			else if (write(2, "ERROR mauvaise option\n", 23))
				exit(-1);
		}
		else if (vm->pct < MAX_PLAYERS)
		{
			vm->names[vm->pct++] = av[i];
			vm->pnum[vm->pct] = -1;
		}
		else if (write(2, "ERROR trop de champions\n", 25))
			exit(-1);
	}
}

int16_t reverser_16(int16_t a)
{
    return (((a & 0xFF00) >> 8) | ((a & 0x00FF) << 8));
}
int32_t reverser_32(int32_t a)
{
    int32_t tmp;
    tmp = 0;
    tmp = ((a & 0xFF000000) >> 24) | ((a & 0x00FF) << 24);
    tmp |= ((a & 0x00FF0000) >> 8) | ((a & 0x0000FF00) << 8);
    return (tmp);
}

int		read_proc(t_proc *current, int fd, unsigned char *prog, char **name) // parse le chmpion
{
	header_t *h;
	int rd;
	(void)name;
	if (!(h = malloc(sizeof(header_t))) && write(1, "MALLOC erreur\n", 14))
		return(-1);
	if ((rd = read(fd, h, sizeof(header_t))) < 0 && write(2, "impossible de lire le fichier\n", 31))
		return (-1);
	if (reverser_32(h->magic) != COREWAR_EXEC_MAGIC && write(2, "Nombre magique faux\n", 21))
		return(-1);
	if (reverser_32(h->prog_size) > CHAMP_MAX_SIZE && write (2, "size du champion trop grande\n", 30))
		return (-1);
	read(fd, prog, CHAMP_MAX_SIZE + 1);
	printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", current->pnu, reverser_32(h->prog_size), h->prog_name, h->comment);
	return(reverser_32(h->prog_size));
}

int		find_playernum(t_vm *vm)
{
	int min;
	int i;
	
	min = 10;
	i = 0;
	while (i++ < MAX_PLAYERS)
		if (min > i && vm->play_free[i] == 0)
			min = i;
	vm->play_free[min] = 1;
	return (min);
}

void	load_proc(t_vm *vm, int fd, t_proc *current, int pn)  //rentre le champion dans la memoire
{
	unsigned char prog[CHAMP_MAX_SIZE];
	int i;

	if ((vm->sizes[pn] = read_proc(current, fd, prog, &vm->names[pn])) == -1)
		exit(-1);
	i = MEM_SIZE / vm->pct + ((int)current->pc >= MEM_SIZE / vm->pct);// verifier
	while (i--)
		vm->mem[current->pc - i] = i >= vm->sizes[pn] ? 0 : prog[i];
	bzero(current->reg, REG_NUMBER * REG_SIZE);
	current->reg[1] = -current->pnu;
}


void	check_proc(t_vm *vm, t_proc *current, int pn)
{
	int fd;

	pushfront_proc(&vm->proc, current);
	if ((fd = open(vm->names[pn], O_RDONLY)) == -1)
	{
		printf("fail to open\nfd = %d", fd);
		exit(-1);
	}
	current->carry = false;
	current->cycle = 0;
	current->pc = MEM_SIZE - 1 - (pn * MEM_SIZE / vm->pct); //pc = emplacement dans la memoire du curseur du processus
	if (vm->pnum[pn] == -1)
		current->pnu = find_playernum(vm);
	else
		current->pnu = vm->pnum[pn];
	load_proc(vm, fd, current, pn);
}

int     initialize(t_vm *vm, int ac, char **av)
{
	int i;
	t_proc *proc;
	
	i = -1;
	bzero(vm->play_free, MAX_PLAYERS);
	vm->dump = -1;
	vm->pct = 0;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->cycle = 0;
	vm->check = 0;
    if (ac > 1)
        parsing(vm, ac, av);
	else if (write (2 ,"USAGE\n", 31))
		exit(-1);//ERROR
	if (!vm->pct && write(2, "Error: please provide champions\n", 32))
		exit(-1);
	printf("Introducing contestants...\n");
	while (++i < vm->pct)
	{
		proc = malloc(sizeof(t_proc));
		check_proc(vm, proc, i);
	}
	i = -1;
	while(++i <MEM_SIZE){              //Print memory
		printf("%x", vm->mem[i]);
	}
	printf("\n--------------------RUN------------------\n");
	return (0);
}