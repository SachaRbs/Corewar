/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:56:05 by sarobber          #+#    #+#             */
/*   Updated: 2019/10/07 18:41:47 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "error.h"

void	pushfront_proc(t_proc **head, t_proc *new)
{
	if (head && *head && new)
	{
		new->next = *head;
		*head = new;
	}
	else
		*head = new;
}

void	parsing(t_vm *vm, int ac, char **av)
{
	int		i;

	i = 0;
	vm->pnum[vm->pct] = -1;
	while (++i < ac)
	{
		if (av[i][0] == '-')
		{
			if (av[i][1] == 'n' && !av[i][2] && ac > ++i)
			{
			// atoi qui check si le numero de -n 'X' est bon ( < MAX_PLAYERS)
				vm->pnum[vm->pct] = ft_atoi(av[i]);
				vm->play_free[vm->pnum[vm->pct]] = 1;
			}
			else if (av[i][1] == 'd')
				vm->dump = ft_atoi(av[i]);
			else
				ft_exit(vm, MAUVAISE_OPTION);
		}
		else if (vm->pct < MAX_PLAYERS)
		{
			vm->names[vm->pct++] = av[i];
			vm->pnum[vm->pct] = -1;
		}
		else
			ft_exit(vm, TROP_DE_CHAMPS);
	}
}

int16_t		reverser_16(int16_t a)
{
	return (((a & 0xFF00) >> 8) | ((a & 0x00FF) << 8));
}

int32_t		reverser_32(int32_t a)
{
	int32_t		tmp;

	tmp = 0;
	tmp = ((a & 0xFF000000) >> 24) | ((a & 0x00FF) << 24);
	tmp |= ((a & 0x00FF0000) >> 8) | ((a & 0x0000FF00) << 8);
	return (tmp);
}

/*
***	PARSE LE CHAMPION
*/

int		read_proc(t_proc *current, int fd, unsigned char *prog, char **name, t_vm *vm)
{
	header_t	*h;
	int			rd;

	(void)name;
	if (!(h = ft_memalloc(sizeof(header_t))))
		ft_exit(vm, ERROR_MALLOC);
	if ((rd = read(fd, h, sizeof(header_t))) < 0)
		ft_exit(vm, FAIL_ON_READ);
	if (reverser_32(h->magic) != COREWAR_EXEC_MAGIC)
		ft_exit(vm, NOMBRE_MAGIQUE);
	if (reverser_32(h->prog_size) > CHAMP_MAX_SIZE)
		ft_exit(vm, SIZE_TROP_GRANDE);
	if (read(fd, prog, CHAMP_MAX_SIZE + 1) < 0)
		ft_exit(vm, FAIL_ON_READ);
	printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
		current->pnu, reverser_32(h->prog_size), h->prog_name, h->comment);
	return (reverser_32(h->prog_size));
}

int		find_playernum(t_vm *vm)
{
	int		i;
	int		min;

	i = 0;
	min = 10;
	while (i++ < MAX_PLAYERS)
		if (min > i && vm->play_free[i] == 0)
			min = i;
	vm->play_free[min] = 1;
	return (min);
}

/*
*** RENTRE LE CHAMPION DANS LA MEMOIRE
*/

void	load_proc(t_vm *vm, int fd, t_proc *current, int pn)
{
	int				i;
	unsigned char	prog[CHAMP_MAX_SIZE];

	if ((vm->sizes[pn] = read_proc(current, fd, prog, &vm->names[pn], vm)) == -1)
		ft_exit(vm, READ_PROCESUS);
	// verifier
	i = MEM_SIZE / vm->pct + ((int)current->pc >= MEM_SIZE / vm->pct);
	while (i--)
		vm->mem[current->pc - i] = i >= vm->sizes[pn] ? 0 : prog[i];
	bzero(current->reg, REG_NUMBER * REG_SIZE);
	current->reg[1] = -current->pnu;
}

void	check_proc(t_vm *vm, t_proc *current, int pn)
{
	int		fd;

	pushfront_proc(&vm->proc, current);
	if ((fd = open(vm->names[pn], O_RDONLY)) == -1)
		ft_exit(vm, FAIL_ON_READ);
	current->carry = false;
	current->cycle = 0;
	//pc = emplacement dans la memoire du curseur du processus
	current->pc = MEM_SIZE - 1 - (pn * MEM_SIZE / vm->pct);
	if (vm->pnum[pn] == -1)
		current->pnu = find_playernum(vm);
	else
		current->pnu = vm->pnum[pn];
	load_proc(vm, fd, current, pn);
}

void	print_memory(unsigned char *mem)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
		printf("%x", mem[i]);
	ft_putendl("\n--------------------RUN------------------");
}

int		initialize(t_vm *vm, int ac, char **av)
{
	int		i;
	t_proc	*proc;

	i = -1;
	ft_bzero(vm->play_free, MAX_PLAYERS + 1);
	ft_bzero(vm->mem, MEM_SIZE);
	vm->dump = -1;
	vm->pct = 0;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->cycle = 0;
	vm->check = 0;
	if (ac > 1)
		parsing(vm, ac, av);
	else
		ft_exit(vm, INVALID_INPUT);
	if (!vm->pct)
		ft_exit(vm, NO_CHAMPIONS);
	ft_putendl("Introducing contestants...");
	while (++i < vm->pct)
	{
		if ((proc = ft_memalloc(sizeof(t_proc*))) == NULL)
			ft_exit(vm, ERROR_MALLOC);
		check_proc(vm, proc, i);
	}
	print_memory(vm->mem);
	return (0);
}
