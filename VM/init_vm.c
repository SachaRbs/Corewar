/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:56:05 by sarobber          #+#    #+#             */
/*   Updated: 2019/09/09 11:20:11 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"
#include <stdio.h>

void    parsing(t_vm *vm, int ac, char **av)
{
	int i;

	i = 0;
	vm->pnum[vm->pct] = -1;
	while (++i < ac)
	{
		if (av[i][0] == '-' )
		{
			if (av[i][1] == 'n' && !av[i][2] && ac > ++i)
				vm->pnum[vm->pct] = ft_atoi(av[i]); // atoi qui check si le numero de -n 'X' est bon ( < MAX_PLAYERS)
			//else if 'a'/ 'd'
			 //
			else if (write(2, "ERROR mauvaise option\n", 23))
				exit(1);//ERROR
		}
		else if (vm->pct < MAX_PLAYERS)
		{
			vm->names[vm->pct++] = av[i];
			vm->pnum[vm->pct] = -1;
		}
		else if (write(2, "ERROR trop de champions\n", 25))
			exit(1);//ERROR
	}
}

 // note un octet hexa= 2 chiffres peut stocker 16^2 = 256 comme un octet en binaire avec 8 chiffres 2^8=256
	// read(fd, (void*)&h.magic, 4); //= f383ea00f383ea00 ??
int		read_proc(t_proc *current, int fd, char *prog, char **name) // parse le chmpion
{ // gestion d'erreur
	header_t h;
	int i;
	
	i = 4;
	while (i-- || !(i = 8)) //on verra
		read(fd, (void*)&h.magic + i, 1);
	read(fd, h.prog_name, PROG_NAME_LENGTH);
	while ((h.magic == COREWAR_EXEC_MAGIC || !(h.prog_size = ~0)) && i--)
		read(fd, (void*)&h.prog_size + i, 1);
	if (h.prog_size > CHAMP_MAX_SIZE || h.magic != COREWAR_EXEC_MAGIC)
		return(-1);
	while (h.prog_name[++i] && (i < PROG_NAME_LENGTH || (h.prog_name[i] = 0)))
		;
	read(fd, h.comment, COMMENT_LENGTH);
	read(fd, &h.magic, 4); // lire 4 octet NUULL si h.magic tester
	read(fd, prog, CHAMP_MAX_SIZE + 1);
	if (!((*name) = malloc(++i)))
		return (-1); //ERROR
	while(i--)
		(*name)[i] = h.prog_name[i];
	close(fd);
	return (1);
}

void	load_proc(t_vm *vm, int fd, t_proc *current, int pn)  //rentre le champion dans la memoire
{
	char prog[CHAMP_MAX_SIZE];
	int i;

	read_proc(current, fd, prog, &vm->names[pn]);
	i = MEM_SIZE / vm->pct + ((int)current->pc >= MEM_SIZE / vm->pct);// verifier
	while (i--)
		vm->mem[current->pc - i] = i >= vm->sizes[pn] ? 0 : prog[i];
	//
		//plein de chose a faire encore
	//
*/}

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

void	check_proc(t_vm *vm, t_proc *current, int pn)
{
	int fd;

	pushfront_proc(&vm->proc, current);
	if ((fd = open(vm->names[pn], O_RDONLY)) == -1){
		printf("fail to open\nfd = %d", fd);
		exit(1);
	}
	current->pc = MEM_SIZE - 1 - (pn * MEM_SIZE / vm->pct); //pc = emplacement dans la memoire du curseur du processus
	load_proc(vm, fd, current, pn);
}

int     initialize(t_vm *vm, int ac, char **av)
{
	int i;
	t_proc *proc;
	
	i = -1;
	vm->pct = 0;
    if (ac > 1)
        parsing(vm, ac, av);
	else if (write (2 ,"ERROR aucun champions fournis\n", 31))
		exit(1);//ERROR
	while (++i < vm->pct)
	{
		proc = malloc(sizeof(t_proc));
		check_proc(vm, proc, i);
	}
	return (0);
}