/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 09:40:54 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/04/16 12:41:43 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_printf_internal(t_context context)
{
	const t_context	next_context = ft_printf_internal_step(context);
	int				result;

	*next_context.remain_format && (result = ft_printf_internal(next_context));
	!*next_context.remain_format && (result = next_context.result);
	return (result);
}
