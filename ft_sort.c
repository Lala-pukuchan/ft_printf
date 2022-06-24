/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:46:16 by rukobaya          #+#    #+#             */
/*   Updated: 2022/06/24 14:29:46 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sort_inputs(const char c, va_list vl)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_output_c(va_arg(vl, int));
	if (c == 's')
		len += ft_output_s(va_arg(vl, char *));
	if (c == 'p')
		len += ft_output_p((unsigned long long)va_arg(vl, void *));
	if (c == 'd' || c == 'i')
		len += ft_output_d(va_arg(vl, int));
	if (c == 'u')
		len += ft_output_u(va_arg(vl, unsigned int));
	if (c == 'x' || c == 'X')
		len += ft_output_x(va_arg(vl, long long), c);
	if (c == '%')
		len += ft_output_c('%');
	return (len);
}

int	ft_sort(const char *inputs, va_list vl)
{
	int	len;

	len = 0;
	while (*inputs)
	{
		if (*inputs == '%')
		{
			inputs++;
			len += ft_sort_inputs(*inputs, vl);
			inputs++;
		}
		else
		{
			len += ft_output_c(*inputs++);
		}
	}
	return (len);
}
