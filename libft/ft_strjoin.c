/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 08:30:57 by rukobaya          #+#    #+#             */
/*   Updated: 2022/05/29 17:32:16 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	p = (char *)ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1, ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strlcat(p, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (p);
}
