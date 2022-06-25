/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 09:10:42 by rukobaya          #+#    #+#             */
/*   Updated: 2022/04/11 19:31:59 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;

	if (dest == src)
		return (NULL);
	pd = (unsigned char *)dest;
	ps = (const unsigned char *)src;
	if (dest < src)
	{
		ft_memcpy(pd, ps, n);
	}
	else
	{
		while (n-- > 0)
			pd[n] = ps[n];
	}
	return (dest);
}
