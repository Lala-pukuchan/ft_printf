/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:13:21 by rukobaya          #+#    #+#             */
/*   Updated: 2022/04/18 19:21:02 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	ln;

	ln = (long long)n;
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln *= (-1);
	}
	if (9 < ln)
		ft_putnbr_fd(ln / 10, fd);
	ft_putchar_fd("0123456789"[ln % 10], fd);
}
