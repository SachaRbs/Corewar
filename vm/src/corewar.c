/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:39:50 by sarobber          #+#    #+#             */
/*   Updated: 2019/10/30 19:04:54 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "operations.h"

unsigned int		big_endian(unsigned int num, int n)
{
	if (n == 1)
		return (num);
	else if (n == 2)
		return (reverser_16(num));
	else if ( n == 4)
		return (reverser_32(num));
	return (-1);
}

unsigned int	get_instruction(t_vm *vm, int size, unsigned int *pc)
{
	int		val;

	val = 0;
	if (*pc + size < MEM_SIZE)
		ft_memcpy(&val, &(vm->mem[*pc]), size);
	else
		val = -1;
	*pc += size;
	return (big_endian(val, size));
}

// int		check_arcode(int action, int arcode)
// {
// 	int code;
	
// 	while (++i < op.nb_arg)
// 	{
// 		code = ((proc->arcode >> (6 - i * 2)) & 3);
// 	}
// }

int		get_arg(t_vm *vm, t_proc *proc, t_op op)
{
	int				i;
	unsigned int	size;
	unsigned int	code;

	i = -1;
	proc->cycle += op.cycle;
	proc->arcode = op.ocp ? get_instruction(vm, 1, &proc->read) : DIR_CODE << 6;
	// if (check_arcode(proc->action, proc->arcode))
	// 	return(0);
	while (++i < MAX_ARGS_NUMBER)
	{
		code = ((proc->arcode >> (6 - i * 2)) & 3); 
		if (i < op.nb_arg)
		{
			if (code == REG_CODE && op.args[i] & T_REG)
				size = 1;
			else if ((code == IND_CODE && op.args[i] & T_IND) || (code == DIR_CODE && op.args[i] & T_DIR))
				size = (code == IND_CODE || op.index) ? IND_SIZE : DIR_SIZE;
			else
				return (0);
			proc->arg_a[i] = proc->read;
			proc->arg_t[i] = code;
			proc->arg_v[i] = get_instruction(vm, size, &proc->read);
		}
		else if (code != 0)
			return (0);
	}
	// if ( code == 0)
		return (1);
	// return (0);
}

void	print_action(t_proc *proc)
{
	int	i;

	i = 0;
	printf("PLAYER No %d :\n", proc->pnu);
	printf("action = %s\n", g_op_tab[proc->action].name);
	while (i < 4){
		printf("arg_v[%d] = %d\n",i, proc->arg_v[i]);
		proc->arg_v[i] = 0;
		i++;
	}
	printf("\n\n");
}

void	print_memory2(unsigned char *mem, t_proc *proc)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if (i == proc->pc)
		{
			printf("\e[36m%02hhx ", mem[i]);
			// printf("%02hhx ", mem[i]);
			printf("\e[0m");
		}
		else if (i > proc->pc && i < (int)proc->read)
		{
			printf("\e[32m%02hhx ", mem[i]);
			printf("\e[0m");
			// printf("%02hhx ", mem[i]);
		}
		else
			printf("%02hhx ", mem[i]);
	}
	printf("\n");
}

void	arg_to_zero(t_proc *proc)
{
	size_t	i;

	i = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		proc->arg_a[i] = 0;
		proc->arg_v[i] = 0;
		proc->arg_t[i] = 0;
		i++;
	}
}

void	run_corewar(t_vm *vm)
{
	t_proc	*proc;
	t_operations	*operation;

	operation = fill_operations(vm);
	while ((vm->dump == -1 || vm->cycle < vm->dump) && ++vm->cycle)
	{
		proc = vm->proc;
		while (proc && proc->pnu)
		{
			if (vm->cycle == proc->cycle)
			{
				operation->op[proc->action - 1](vm, proc);
				print_memory2(vm->mem, proc);
				getchar();
				proc->pc = proc->read;
				arg_to_zero(proc);
			}
			else if (proc->cycle < vm->cycle)
			{
				proc->read = proc->pc;
				proc->action = get_instruction(vm, 1, &proc->read);
				if (!(proc->action > 0 && proc->action <= NBR_OP
				&& get_arg(vm, proc, g_op_tab[proc->action])))
					proc->pc++;
			}
			proc = proc->next;
		}
	}
}
// when we move the pc higher than MEMN_MAX just put it to 0
