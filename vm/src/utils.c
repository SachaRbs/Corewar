/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sacha <sacha@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/10 16:54:05 by sarobber     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/03 19:26:29 by sacha       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "corewar.h"
#include "error.h"

int16_t				reverser_16(int16_t a)
{
	return (((a & 0xFF00) >> 8) | ((a & 0x00FF) << 8));
}

int32_t				reverser_32(int32_t a)
{
	int32_t		tmp;

	tmp = 0;
	tmp = ((a & 0xFF000000) >> 24) | ((a & 0x00FF) << 24);
	tmp |= ((a & 0x00FF0000) >> 8) | ((a & 0x0000FF00) << 8);
	return (tmp);
}

unsigned int		big_endian(unsigned int num, int n)
{
	if (n == 1)
		return (num);
	else if (n == 2)
		return (reverser_16(num));
	else if (n == 4)
		return (reverser_32(num));
	return (-1);
}

int					mod_address(int add)
{
	while (add >= MEM_SIZE)
		add -= MEM_SIZE;
	while (add < 0)
		add += MEM_SIZE;
	return (add);
}

int					argument(t_vm *vm, t_proc *proc, int arg)
{
	if (proc->arg_t[arg] == REG_CODE)
		return (proc->reg[proc->arg_v[arg]]);
	if (proc->arg_t[arg] == DIR_CODE)
		return (proc->arg_v[arg]);
	return(read_mem(vm, proc->arg_v[arg], 4));
}

int		find_procnum(t_vm *vm)
{
	int			out;
	t_proc		*current;

	out = 0;
	current = vm->proc;
	while (current)
	{
		if (out <= current->procnum)
			out = current->procnum + 1;
		current = current->next;
	}
	return (out);
}