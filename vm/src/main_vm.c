/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 12:15:41 by sarobber          #+#    #+#             */
/*   Updated: 2019/10/03 18:58:09 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int main(int ac, char **av)
{
    t_vm *vm;

    vm = ft_memalloc(sizeof(t_vm*));
    initialize(vm, ac, av);
	run_corewar(vm);
	return (0);
}