/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal_p.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:41:03 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/04/16 12:41:16 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

#include <stdarg.h>

#include <sys/_types/_uintptr_t.h>
#include <unistd.h>

static int	internal(uintptr_t i)
{
	uintptr_t	result;
	char		digit;

	result = 0;
	i && (result += internal(i / 16));
	digit = "0123456789abcdef"[i % 16];
	i && (result += write(STDOUT_FILENO, &digit, 1));
	return (result);
}

t_context	ft_printf_internal_p(t_context context)
{
	void *const		v = va_arg(*context.pap, void *);
	const uintptr_t	i = *((uintptr_t *)&v);
	t_context		result;

	result = context;
	result.result += write(STDOUT_FILENO, "0x", 2);
	!i && (result.result += write(STDOUT_FILENO, "0", 1));
	i && (result.result += internal(i));
	result.remain_format++;
	return (result);
}
