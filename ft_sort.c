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

# include "ft_printf.h"

int	ft_sort(const char* inputs, va_list input_list)
{
	int	output_len;

	output_len = 0;
	while (*inputs)
	{
		if (*inputs == '%')
		{
			inputs++;
			switch (*inputs)
			{
				case 'c':
					output_len += ft_output_c(va_arg(input_list, int));
					break;
				case 's':
					output_len += ft_output_s(va_arg(input_list, char*));
					break;
				case 'p':
					output_len += ft_output_p((unsigned long long)va_arg(input_list, void *));
					break;
				case 'd':
					output_len += ft_output_d(va_arg(input_list, int));
					break;
				case 'i':
					output_len += ft_output_d(va_arg(input_list, int));
					break;
				case 'u':
					output_len += ft_output_u(va_arg(input_list, unsigned int));
					break;
				case 'x':
					output_len += ft_output_x(va_arg(input_list, long long), 0);
					break;
				case 'X':
					output_len += ft_output_x(va_arg(input_list, long long), 1);
					break;
				case '%':
					output_len += ft_output_c('%');
					break;
				default:
					break;
			}
			inputs++;
		} else {
			output_len += ft_output_c(*inputs++);
		}
	}
}
