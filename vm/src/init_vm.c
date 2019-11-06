/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:56:05 by sarobber          #+#    #+#             */
/*   Updated: 2019/11/06 15:05:39 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "error.h"

void	parsing(t_vm *vm, int ac, char **av)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-')
			i = get_option(vm, av, ac, i);
		else if (vm->pct < MAX_PLAYERS)
		{
			vm->names[vm->pct] = av[i];
			if (!vm->pnum[vm->pct])
				vm->pnum[vm->pct] = -1;
			vm->pct++;
		}
		else
			ft_exit(vm, TROP_DE_CHAMPS);
	}
}

/*
***	PARSE LE CHAMPION
*/

int		read_proc(t_proc *current, int fd, unsigned char *prog, t_vm *vm)
{
	t_header	*h;
	int			rd;
	int32_t		out;

	if (!(h = (t_header*)ft_memalloc(sizeof(t_header))))
		ft_exit(vm, ERROR_MALLOC);
	if ((rd = read(fd, h, sizeof(t_header))) < 0)
		ft_exit(vm, FAIL_ON_READ);
	if (reverser_32(h->magic) != COREWAR_EXEC_MAGIC)
		ft_exit(vm, NOMBRE_MAGIQUE);
	if (reverser_32(h->prog_size) > CHAMP_MAX_SIZE)
		ft_exit(vm, SIZE_TROP_GRANDE);
	if (read(fd, prog, INT_MAX) < 0)
		ft_exit(vm, FAIL_ON_READ);
	ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
		current->pnu, reverser_32(h->prog_size), h->prog_name, h->comment);
	if (!(vm->contestants[current->pnu] = (char*)ft_memalloc(sizeof(char)
	* ft_strlen(h->prog_name))))
		ft_exit(vm, ERROR_MALLOC);
	ft_strcpy(vm->contestants[current->pnu], h->prog_name);
	out = reverser_32(h->prog_size);
	free(h);
	h = NULL;
	return (out);
}

/*
*** RENTRE LE CHAMPION DANS LA MEMOIRE
*/

void	load_proc(t_vm *vm, int fd, t_proc *current, int pn)
{
	int				i;
	unsigned char	prog[CHAMP_MAX_SIZE];

	if ((vm->sizes[pn] = read_proc(current, fd, prog, vm)) == -1)
		ft_exit(vm, READ_PROCESUS);
	i = -1;
	while (++i < vm->sizes[pn])
		vm->mem[current->pc + i] = prog[i];
	bzero(current->reg, REG_NUMBER * REG_SIZE);
	current->reg[1] = -current->pnu;
}

void	check_proc(t_vm *vm, t_proc *current, int pn)
{
	int		fd;

	pushfront_proc(&vm->proc, current);
	if ((fd = open(vm->names[pn], O_RDONLY)) == -1)
		ft_exit(vm, FAIL_ON_READ);
	current->carry = FALSE;
	current->cycle = 0;
	current->procnum = !vm->proc ? 1 : find_procnum(vm);
	vm->procct = current->procnum;
	current->pc = pn * (MEM_SIZE / vm->pct);
	if (vm->pnum[pn] == -1)
		current->pnu = find_playernum(vm);
	else
		current->pnu = vm->pnum[pn];
	current->alive = 1;
	load_proc(vm, fd, current, pn);
}

int		initialize(t_vm *vm, int ac, char **av)
{
	int		i;
	t_proc	*proc;

	i = -1;
	set_values_vm(vm);
	if (ac > 1)
		parsing(vm, ac, av);
	else
		ft_exit(vm, INVALID_INPUT);
	if (!vm->pct)
		ft_exit(vm, NO_CHAMPIONS);
	ft_putendl("Introducing contestants...");
	while (++i < vm->pct)
	{
		if (!(proc = (t_proc*)ft_memalloc(sizeof(t_proc))))
			ft_exit(vm, ERROR_MALLOC);
		proc->next = NULL;
		check_proc(vm, proc, i);
	}
	vm->last_alive = find_player_alive(vm);
	return (0);
}
