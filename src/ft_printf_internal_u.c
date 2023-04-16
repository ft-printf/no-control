/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal_u.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:41:03 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/04/16 12:41:25 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

#include <stdarg.h>

#include <unistd.h>

static int	internal(unsigned int i)
{
	unsigned int	result;
	char			digit;

	result = 0;
	i && (result += internal(i / 10));
	digit = i % 10 + '0';
	i && (result += write(STDOUT_FILENO, &digit, 1));
	return (result);
}

t_context	ft_printf_internal_u(t_context context)
{
	const unsigned int	i = va_arg(*context.pap, unsigned int);
	t_context			result;

	result = context;
	!i && (result.result += write(STDOUT_FILENO, "0", 1));
	i && (result.result += internal(i));
	result.remain_format++;
	return (result);
}
