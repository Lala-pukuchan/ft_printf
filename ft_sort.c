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
	int	output_len;

	output_len = 0;
	while (*inputs)
	{
		if (*inputs == '%')
		{
			inputs++;
			if (*inputs == 'c')
				output_len += ft_output_c(va_arg(input_list, int));
			if (*inputs == 's')
				output_len += ft_output_s(va_arg(input_list, char*));
			if (*inputs == 'p')
				output_len += ft_output_p((unsigned long long)va_arg(input_list, void *));
			if (*inputs == 'd' || *inputs == 'i')
				output_len += ft_output_d(va_arg(input_list, int));
			if (*inputs == 'u')
				output_len += ft_output_u(va_arg(input_list, unsigned int));
			if (*inputs == 'x')
				output_len += ft_output_x(va_arg(input_list, long long), 0);
			if (*inputs == 'X')
				output_len += ft_output_x(va_arg(input_list, long long), 1);
			if (*inputs == '%') 
				output_len += ft_output_c('%');
			inputs++;
		} else {
			output_len += ft_output_c(*inputs++);
		}
	}
}
