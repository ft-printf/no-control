/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal_d.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:41:03 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/04/16 12:41:10 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

#include <stdarg.h>

#include <unistd.h>

static int	internal(int i)
{
	int		result;
	char	digit;
	int		sign;

	sign = 1;
	(i < 0) && (sign = -1);
	result = 0;
	i && (result += internal(i / 10));
	digit = (i % 10) * sign + '0';
	i && (result += write(STDOUT_FILENO, &digit, 1));
	return (result);
}

t_context	ft_printf_internal_d(t_context context)
{
	const int	i = va_arg(*context.pap, int);
	t_context	result;

	result = context;
	i == 0 && (result.result += write(STDOUT_FILENO, "0", 1));
	i < 0 && (result.result += write(STDOUT_FILENO, "-", 1));
	i && (result.result += internal(i));
	result.remain_format++;
	return (result);
}
