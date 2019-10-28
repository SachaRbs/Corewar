/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:20:58 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/08 15:28:55 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum	e_errors
{
	ERROR_MALLOC,
	INVALID_INPUT,
	NO_CHAMPIONS,
	FAIL_ON_READ,
	NOMBRE_MAGIQUE,
	SIZE_TROP_GRANDE,
	MAUVAISE_OPTION,
	TROP_DE_CHAMPS,
	READ_PROCESUS
}				t_errors;

void			ft_exit(t_vm *vm, t_errors error);
void			close_program(t_vm *vm, int out);

#endif
