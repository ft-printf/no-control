/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 09:29:44 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/04/16 10:10:36 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>
#include <stdlib.h>

#include "ft_printf_internal.h"

int	ft_printf(const char *format, ...)
{
	t_context	context;
	va_list		ap;
	int			result;

	va_start(ap, format);
	context.remain_format = format;
	context.pap = &ap;
	context.result = 0;
	result = 0;
	*format && (result = ft_printf_internal(context));
	va_end(ap);
	return (result);
}
