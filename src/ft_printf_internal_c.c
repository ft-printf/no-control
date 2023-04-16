/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal_c.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 10:23:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/04/16 12:41:07 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

#include <stdarg.h>

#include <unistd.h>

t_context	ft_printf_internal_c(t_context context)
{
	t_context	result;
	const char	c = (char)va_arg(*context.pap, int);

	result = context;
	result.result += write(STDOUT_FILENO, &c, 1);
	result.remain_format++;
	return (result);
}
