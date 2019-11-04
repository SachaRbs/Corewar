/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sti.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sacha <sacha@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 20:31:34 by crfernan     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/02 18:52:00 by sacha       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "operations.h"
#include "error.h"
#include "op.h"

/*
***		MODIFY to calculate the pc with the function mod_address
*/

void	*ft_sti(t_vm *vm, t_proc *proc)
{
	// int i;
	int pc;
	int address;

	// i = proc->pc;
	// printf("ADV %d (0x%04x -> 0x%04x) ", proc->read - proc->pc, proc->pc, proc->read);
	// while (i < proc->pc + 10)
	// {
	// 	printf("%d [%02hhx] ", i, vm->mem[mod_address(i)]);
	// 	i++;
	// }
	// printf("\n");

	// if (proc->pc < 0)
	// 	proc->pc = MEM_SIZE + proc->pc;

	pc = mod_address(proc->pc);
	address = pc + ((argument(vm, proc, 1) + argument(vm, proc, 2)) % IDX_MOD);
	// address = mod_address(pc + ((argument(vm, proc, 1) + argument(vm, proc, 2)) % IDX_MOD));
	writing_mem(vm, address, 4, proc->reg[proc->arg_v[0]]);

	return (NULL);
}
