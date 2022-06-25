/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 09:04:15 by rukobaya          #+#    #+#             */
/*   Updated: 2022/05/29 14:54:02 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*pd;
	const unsigned char	*ps;

	if (dest == src)
		return (dest);
	i = 0;
	pd = (unsigned char *)dest;
	ps = (const unsigned char *)src;
	while (i < n)
	{
		pd[i] = ps[i];
		i++;
	}
	return (dest);
}
