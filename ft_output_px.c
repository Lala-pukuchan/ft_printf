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

// 2進数の場合、8 -> 100
// 8%2=0 8/2=4, 4%2=0 4/2=2, 2%2=0 2/2=1
// 16進数で利用する文字列の配列を渡してしまう。
// sizeはmalloc用の桁数。
// malloc後にfreeすること。
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
		// 配列のindexの為、countを先に引いてから、そこに代入する。
		p[--count] = str[n % base];
		n /= base;
	}
	return (p);
}

// 16進数8桁で表現できる最大値: n^(桁数-1)×桁の値 = 16^(8-1)*15 = 4026531840
// unsigned long longの最大値: 18446744073709551615
// unsigned longの最大値: 18446744073709551615
// unsigned intの最大値: 4294967295
int	ft_output_p(unsigned long long p) 
{
	char	*converted;
	int		len;

	// アドレス値を、16進数で出力する為。
	converted = ft_convert(p, 16, "0123456789abcdef");
	// 先頭に16進数の目印である0xをつける。（先に出力してしまう。）
	ft_output_s("0x");
	len = ft_output_s(converted);
	// 変換した文字列格納用メモリを解放。
	free(converted);
	return (len + 2);
}

int	ft_output_x(long long n, int upper_flag) 
{
	char	*converted;
	int		len;

	// アドレス値を、16進数で出力する為。
	// LONG_MAXをUNSIGNED_INT_MAXで出力したいので、unsigned intに変換。
	// intが負の値の場合は？
	if (upper_flag)
		converted = ft_convert((unsigned int)n, 16, "0123456789ABCDEF");
	else
		converted = ft_convert((unsigned int)n, 16, "0123456789abcdef");
	// x, Xの場合、0xを先頭につける必要無し。
	// 先頭に16進数の目印である0xをつける。（先に出力してしまう。）
	// ft_output_s("0x");
	len = ft_output_s(converted);
	// 変換した文字列格納用メモリを解放。
	free(converted);
	return (len);
}
