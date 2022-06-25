/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 08:44:36 by rukobaya          #+#    #+#             */
/*   Updated: 2022/05/29 16:57:13 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_delimiter(char const *s, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i + 1] == c && i != (ft_strlen(s) - 2))
			count++;
		i++;
	}
	return (count + 1);
}

static char	**ft_free_array(char **array, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		free(array[idx]);
		array[idx] = NULL;
	}
	free(array);
	array = NULL;
	return (NULL);
}

static char	**ft_create_array(char **array, int idx, char const *s, char c)
{
	int		len;

	while (*s != '\0')
	{
		while ((*s == c) && (*s != '\0'))
			s++;
		len = 0;
		while ((*s != c) && (*s != '\0'))
		{
			s++;
			len++;
		}
		if (len != 0)
		{
			array[idx] = ft_substr(s - len, 0, len);
			if (!array[idx])
				return (ft_free_array(array, idx));
			idx++;
		}
	}
	array[idx] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (ft_count_delimiter(s, c) + 1));
	if (!array)
		return (NULL);
	return (ft_create_array(array, 0, s, c));
}
