/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:52:17 by rukobaya          #+#    #+#             */
/*   Updated: 2022/04/12 08:57:05 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;

	p = (char *)malloc(ft_strlen(s) + 1);
	if (!p)
		return (NULL);
	ft_strlcpy(p, s, ft_strlen(s) + 1);
	return (p);
}
