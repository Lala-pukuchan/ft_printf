/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:46:25 by rukobaya          #+#    #+#             */
/*   Updated: 2022/06/23 15:46:26 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char	*ft_utoa(unsigned int n)
{
	int				digit;
	char			*str;
	unsigned int	num;

	num = n;
	digit = ft_getdigit(num);
	str = (char *)malloc(digit + 1);
	if (!str)
		return (NULL);
	return (ft_convertint(str, 0, num, digit));
}
