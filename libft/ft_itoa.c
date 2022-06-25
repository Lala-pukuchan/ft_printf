/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:58:15 by rukobaya          #+#    #+#             */
/*   Updated: 2022/04/16 17:57:58 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getpower(int p)
{
	int	tenpower;

	tenpower = 1;
	while (p-- > 0)
		tenpower *= 10;
	return (tenpower);
}

static int	ft_getdigit(unsigned int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_convertint(char *str, size_t index, unsigned int n, int digit)
{
	while (1 < digit)
	{
		str[index++] = '0' + (n / ft_getpower(digit - 1));
		n %= ft_getpower(digit - 1);
		digit--;
	}
	str[index++] = '0' + (n % 10);
	str[index] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int				digit;
	char			*str;
	size_t			index;
	unsigned int	num;

	index = 0;
	if (n < 0)
	{
		num = n * (-1);
		digit = ft_getdigit(num);
		str = (char *)malloc(digit + 2);
		if (!str)
			return (NULL);
		str[index++] = '-';
	}
	else
	{
		num = n;
		digit = ft_getdigit(num);
		str = (char *)malloc(digit + 1);
		if (!str)
			return (NULL);
	}
	return (ft_convertint(str, index, num, digit));
}
