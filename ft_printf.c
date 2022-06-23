/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:20:46 by rukobaya          #+#    #+#             */
/*   Updated: 2022/06/23 15:45:38 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int	ft_printf(const char * inputs, ...)
{
	int	output_len;
    va_list	input_list;
	// mallocをどこで利用するのか要確認。
    va_start(input_list, inputs);
	output_len = ft_sort(inputs, input_list);
    va_end(input_list);
	return (output_len);
}
