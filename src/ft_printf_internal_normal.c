/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal_normal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 10:20:49 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/04/16 10:21:50 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

#include <unistd.h>

t_context	ft_printf_internal_normal(t_context context)
{
	t_context	result;

	result = context;
	result.result += write(STDOUT_FILENO, result.remain_format++, 1);
	return (result);
}
