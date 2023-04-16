/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 09:29:01 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/04/16 12:44:20 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# include <stdarg.h>
# include <stdbool.h>

typedef struct s_context
{
	const char	*remain_format;
	va_list		*pap;
	int			result;
}	t_context;

int			ft_printf_internal(t_context context);
int			ft_printf_internal_assign(t_context *address, t_context value);
t_context	ft_printf_internal_step(t_context context);
t_context	ft_printf_internal_normal(t_context context);
t_context	ft_printf_internal_format(t_context context);
t_context	ft_printf_internal_dummy(t_context context);
t_context	ft_printf_internal_c(t_context context);
t_context	ft_printf_internal_s(t_context context);
t_context	ft_printf_internal_p(t_context context);
t_context	ft_printf_internal_d(t_context context);
t_context	ft_printf_internal_i(t_context context);
t_context	ft_printf_internal_u(t_context context);
t_context	ft_printf_internal_x(t_context context);
t_context	ft_printf_internal_uppercase_x(t_context context);
t_context	ft_printf_internal_percent(t_context context);

#endif
