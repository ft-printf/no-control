/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal_format.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 09:48:44 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/04/16 12:45:36 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

t_context	ft_printf_internal_format(t_context context)
{
	const char	format = context.remain_format[1];
	t_context	result;

	result = ft_printf_internal_dummy(context);
	(format == 'c') && (
ft_printf_internal_assign(&result, ft_printf_internal_c(result)));
	(format == 's') && (
ft_printf_internal_assign(&result, ft_printf_internal_s(result)));
	(format == 'p') && (
ft_printf_internal_assign(&result, ft_printf_internal_p(result)));
	(format == 'd') && (
ft_printf_internal_assign(&result, ft_printf_internal_d(result)));
	(format == 'i') && (
ft_printf_internal_assign(&result, ft_printf_internal_i(result)));
	(format == 'u') && (
ft_printf_internal_assign(&result, ft_printf_internal_u(result)));
	(format == 'x') && (
ft_printf_internal_assign(&result, ft_printf_internal_x(result)));
	(format == 'X') && (
ft_printf_internal_assign(&result, ft_printf_internal_uppercase_x(result)));
	(format == '%') && (
ft_printf_internal_assign(&result, ft_printf_internal_percent(result)));
	return (result);
}
