/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:13:07 by rukobaya          #+#    #+#             */
/*   Updated: 2022/04/24 11:08:49 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ps;
	unsigned char		uc;

	i = 0;
	ps = (const unsigned char *)s;
	uc = (unsigned char)c;
	while (i < n)
	{
		if (ps[i] == uc)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
