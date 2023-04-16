/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal_s.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 10:23:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/04/16 12:51:18 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

#include <stdarg.h>
#include <stdlib.h>

#include <unistd.h>

static size_t	len(const char *str)
{
	size_t	result;

	result = 0;
	*str && (result = 1 + len(str + 1));
	return (result);
}

t_context	ft_printf_internal_s(t_context context)
{
	t_context	result;
	const char	*str = va_arg(*context.pap, const char *);

	str || (str = "(null)");
	result = context;
	result.result += write(STDOUT_FILENO, str, len(str));
	result.remain_format++;
	return (result);
}
