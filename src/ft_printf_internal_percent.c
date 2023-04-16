/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal_percent.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 10:23:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/04/16 12:41:19 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

#include <unistd.h>

t_context	ft_printf_internal_percent(t_context context)
{
	t_context	result;

	result = context;
	result.result += write(STDOUT_FILENO, "%", 1);
	result.remain_format++;
	return (result);
}
