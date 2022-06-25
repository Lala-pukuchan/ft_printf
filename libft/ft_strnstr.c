/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:45:07 by rukobaya          #+#    #+#             */
/*   Updated: 2022/04/11 19:23:21 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_checkstr(const char *b, const char *l, int i, size_t rl)
{
	size_t	j;
	size_t	len;

	j = 0;
	len = ft_strlen(l);
	while (l[j] != '\0' && rl > 0)
	{
		if (b[i++] != l[j++])
			return (0);
		rl--;
		len--;
	}
	if (len > 0 && rl == 0)
		return (0);
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (len > 0 && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			if (ft_checkstr(big, little, i, len))
				return ((char *)big + i);
		}
		i++;
		len--;
	}
	return (NULL);
}
