/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:00:36 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/15 19:14:01 by crfernan         ###   ########.fr       */
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

/*
***	PARSE LE CHAMPION
*** This function had as argument [char **name] and setting it to void (???)
*/

int		read_proc(t_proc *current, int fd, unsigned char *prog, t_vm *vm)
{
	header_t	*h;
	int			rd;

	if (!(h = ft_memalloc(sizeof(header_t))))
		ft_exit(vm, ERROR_MALLOC);
	if ((rd = read(fd, h, sizeof(header_t))) < 0)
		ft_exit(vm, FAIL_ON_READ);
	if (reverser_32(h->magic) != COREWAR_EXEC_MAGIC)
		ft_exit(vm, NOMBRE_MAGIQUE);
	if (reverser_32(h->prog_size) > CHAMP_MAX_SIZE)
		ft_exit(vm, SIZE_TROP_GRANDE);
	if (read(fd, prog, INT_MAX) < 0)
		ft_exit(vm, FAIL_ON_READ); // check size of champ
	printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
		current->pnu, reverser_32(h->prog_size), h->prog_name, h->comment);
	return (reverser_32(h->prog_size));
}

int		find_playernum(t_vm *vm)
{
	int		i;
	int		min;

	i = 0;
	min = 20;
	while (i++ < MAX_PLAYERS)
		if (min > i && vm->play_free[i] == 0)
			min = i;
	vm->play_free[min] = 1;
	return (min);
}

/*
*** RENTRE LE CHAMPION DANS LA MEMOIRE
***
***		Before the memory was filled the other way arround:
***		i = MEM_SIZE / vm->pct + ((int)current->pc >= MEM_SIZE / vm->pct);
***		while (i--)
***			vm->mem[current->pc - i] = i >= vm->sizes[pn] ? 0 : prog[i];
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

/*
***		Before the memory was filled the other way arround:
***		current->pc = MEM_SIZE - 1 - (pn * MEM_SIZE / vm->pct);
*/

void	check_proc(t_vm *vm, t_proc *current, int pn)
{
	int		fd;

	pushfront_proc(&vm->proc, current);
	if ((fd = open(vm->names[pn], O_RDONLY)) == -1)
		ft_exit(vm, FAIL_ON_READ);
	current->carry = FALSE;
	current->cycle = 0;
	current->pc = pn * (MEM_SIZE / vm->pct);
	if (vm->pnum[pn] == -1)
		current->pnu = find_playernum(vm);
	else
		current->pnu = vm->pnum[pn];
	load_proc(vm, fd, current, pn);
}
