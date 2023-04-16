/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal_step.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 10:15:48 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/04/16 10:17:57 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

t_context	ft_printf_internal_step(t_context context)
{
	t_context	result;

	(*context.remain_format == '%') && (
ft_printf_internal_assign(&result, ft_printf_internal_format(context)));
	(*context.remain_format != '%') && (
ft_printf_internal_assign(&result, ft_printf_internal_normal(context)));
	return (result);
}
