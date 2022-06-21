/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:20:46 by rukobaya          #+#    #+#             */
/*   Updated: 2022/06/20 20:57:43 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "printf.h"

int	ft_sort(const char* inputs, va_list input_list)
{
	int	output_len;

	output_len = 0;
	while (*inputs)
	{
		if (*inputs == '%')
			inputs++;
		switch (*inputs)
		{
			case 'c':
				output_len += ft_output_c(va_arg(input_list, int));
				break;
			case 's':
				output_len += ft_output_s(va_arg(input_list, char*));
				break;
			case 'p':
				// どのデータ型のポインタも受け取れるように、void*を指定。
				// ポインタとしてでなく、アドレス値を受け取れるようにキャスト。
				// なぜかunsigned intでキャストできない。
				output_len += ft_output_p((unsigned long long)va_arg(input_list, void *));
				break;
			case 'd':
				output_len += ft_output_d(va_arg(input_list, int));
				break;
			case 'i':
				// dとiは、どちらも10進数で整数を出力する。
				output_len += ft_output_d(va_arg(input_list, int));
				break;
			case 'u':
				// u指定時は、unsigned intを出力する。
				// []To Do: 負の値の出力を確認。
				output_len += ft_output_u(va_arg(input_list, unsigned int));
				break;
			case 'x':
				// 整数を16進数で出力する。
				// 対応: int, short, unsigned int, unsigned short
				// shortはintより小さい、２バイト分整数を格納する。
				// []To Do: unsigned intも対応できるようにする必要あり。
				// []To Do: freeを確認。
				output_len += ft_output_x(va_arg(input_list, long long), 0);
				break;
			case 'X':
				// X指定時の型変換方法調査必要
				output_len += ft_output_x(va_arg(input_list, long long), 1);
				break;
			case '%':
				// %が二つ連続したときは、%を出力する。
				output_len += ft_output_c('%');
				break;
			default:
				puts("エラー: データタイプに異常が有ります。");
				break;
		}
		// ログ出力用
		// printf("\ndata type = %c\noutput len = %d\n", *inputs, output_len);
		inputs++;
	}
	return (output_len); // NULL終端を含める。
}
