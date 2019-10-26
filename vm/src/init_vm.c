/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_vm.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sacha <sacha@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/05 13:56:05 by sarobber     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/26 17:11:01 by sacha       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
	while (++i < ac)
	{
		if (av[i][0] == '-')
		{
			if (av[i][1] == 'n' && !av[i][2] && ac > ++i)
			{
				if ((vm->pnum[vm->pct] = ft_atoi(av[i])) > MAX_PLAYERS)
					ft_exit(vm, INVALID_INPUT);
				vm->play_free[vm->pnum[vm->pct]] = 1;
			}
			else if (av[i][1] == 'd' && !av[i][2] && ac > ++i)
				vm->dump = ft_atoi(av[i]);
			else
				ft_exit(vm, MAUVAISE_OPTION);
		}
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
	if (read(fd, prog, INT_MAX) < 0) // check size of champ
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
	min = 20; 
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
	// i = MEM_SIZE / vm->pct + ((int)current->pc >= MEM_SIZE / vm->pct);
	// while (i--)
	// 	vm->mem[current->pc - i] = i >= vm->sizes[pn] ? 0 : prog[i];
	i = -1;
	while (++i < vm->sizes[pn])
		vm->mem[current->pc + i] = prog[i];
	bzero(current->reg, REG_NUMBER * REG_SIZE);
	current->reg[1] = -current->pnu; //This was one, but the first reg it's the one containing te player number, to it's reg[0]
}

void	check_proc(t_vm *vm, t_proc *current, int pn)
{
	int		fd;

	pushfront_proc(&vm->proc, current);
	if ((fd = open(vm->names[pn], O_RDONLY)) == -1)
		ft_exit(vm, FAIL_ON_READ);
	current->carry = FALSE;
	current->cycle = 0;
	current->procnum = 1;
	// current->pc = MEM_SIZE - 1 - (pn * MEM_SIZE / vm->pct);
	current->pc = pn * (MEM_SIZE / vm->pct);
	if (vm->pnum[pn] == -1)
		current->pnu = find_playernum(vm);
	else
		current->pnu = vm->pnum[pn];
	load_proc(vm, fd, current, pn);
}

int		find_player_alive(t_vm *vm)
{
	int max;
	t_proc *current;

	current = vm->proc;
	max = -1;
	while(current)
	{
		if (current->pnu > max)
			max = current->pnu;
		current = current->next;
	}
	return(max);
}

int		initialize(t_vm *vm, int ac, char **av)
{
	int		i;
	t_proc	*proc;

	i = -1;
	ft_bzero(vm->play_free, (MAX_PLAYERS + 1) * sizeof(int));
	ft_bzero(vm->pnum, (MAX_PLAYERS + 1) * sizeof(int));
	ft_bzero(vm->sizes, (MAX_PLAYERS + 1) * sizeof(long));
	ft_bzero(vm->names, MAX_PLAYERS); // * sizeof(something)
	ft_bzero(vm->mem, MEM_SIZE * sizeof(unsigned char));
	vm->dump = -1;
	vm->pct = 0;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->next_check = vm->cycle_to_die;
	vm->cycle = 0;
	vm->check = 0;
	vm->nbr_live = 0;
	if (ac > 1)
		parsing(vm, ac, av);
	else
		ft_exit(vm, INVALID_INPUT);
	if (!vm->pct)
		ft_exit(vm, NO_CHAMPIONS);
	ft_putendl("Introducing contestants...");
	while (++i < vm->pct)
	{
		if ((proc = ft_memalloc(sizeof(t_proc))) == NULL)
			ft_exit(vm, ERROR_MALLOC);
		check_proc(vm, proc, i);
	}
	vm->last_alive = find_player_alive(vm);
	return (0);
}
