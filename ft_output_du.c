/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_du.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:45:52 by rukobaya          #+#    #+#             */
/*   Updated: 2022/06/23 15:45:53 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_output_d(int n)
{
	char	*p;
	int		len;

	p = ft_itoa(n);
	ft_putstr_fd(p, 1);
	len = ft_strlen(p);
	free(p);
	return (len);
}

int	ft_output_u(unsigned int n)
{
	char	*p;
	int		len;

	p = ft_utoa(n);
	ft_putstr_fd(p, 1);
	len = ft_strlen(p);
	free(p);
	return (len);
}
