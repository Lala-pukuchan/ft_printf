/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:46:16 by rukobaya          #+#    #+#             */
/*   Updated: 2022/06/23 15:46:20 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sort(const char *inputs, va_list input_list)
{
	int	len;

	len = 0;
	while (*inputs)
	{
		if (*inputs == '%')
		{
			inputs++;
			if (*inputs == 'c')
				len += ft_output_c(va_arg(input_list, int));
			if (*inputs == 's')
				len += ft_output_s(va_arg(input_list, char*));
			if (*inputs == 'p')
				len += ft_output_p((unsigned long long)va_arg(input_list, void *));
			if (*inputs == 'd' || *inputs == 'i')
				len += ft_output_d(va_arg(input_list, int));
			if (*inputs == 'u')
				len += ft_output_u(va_arg(input_list, unsigned int));
			if (*inputs == 'x' || *inputs == 'X')
				len += ft_output_x(va_arg(input_list, long long), *inputs);
			if (*inputs == '%')
				len += ft_output_c('%');
			inputs++;
		}
		else
		{
			len += ft_output_c(*inputs++);
		}
	}
}
