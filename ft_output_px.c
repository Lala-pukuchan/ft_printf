/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_px.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:46:05 by rukobaya          #+#    #+#             */
/*   Updated: 2022/06/23 15:46:37 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

static char	*ft_convert(unsigned long n, int base, char *str)
{
	size_t			count;
	unsigned long	tmp;
	char			*p;

	if (n == 0)
		return (ft_strdup("0"));
	tmp = n;
	count = 0;
	while (1 <= tmp)
	{
		tmp /= base;
		count++;
	}
	p = ft_calloc(sizeof(char), count + 1);
	if (!p)
		return (NULL);
	while (1 <= n)
	{
		p[--count] = str[n % base];
		n /= base;
	}
	return (p);
}

int	ft_output_p(unsigned long long p) 
{
	char	*converted;
	int		len;

	converted = ft_convert(p, 16, "0123456789abcdef");
	ft_output_s("0x");
	len = ft_output_s(converted);
	free(converted);
	return (len + 2);
}

int	ft_output_x(long long n, int upper_flag) 
{
	char	*converted;
	int		len;

	if (upper_flag)
		converted = ft_convert((unsigned int)n, 16, "0123456789ABCDEF");
	else
		converted = ft_convert((unsigned int)n, 16, "0123456789abcdef");
	len = ft_output_s(converted);
	free(converted);
	return (len);
}
