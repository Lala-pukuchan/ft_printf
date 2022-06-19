/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:20:46 by rukobaya          #+#    #+#             */
/*   Updated: 2022/06/20 08:11:22 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

int	ft_output_c(const char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_output_s(char* str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_output_d(int n)
{
	char	*p;
	int		len;

	p = ft_itoa(n);
	ft_putstr_fd(p, 1);
	len = ft_strlen(p);
	free(p);
	return (len);
}

int	ft_output_u(unsigned int n)
{
	char	*p;
	int		len;

	p = ft_utoa(n);
	ft_putstr_fd(p, 1);
	len = ft_strlen(p);
	free(p);
	return (len);
}


// 2進数の場合、8 -> 100
// 8%2=0 8/2=4, 4%2=0 4/2=2, 2%2=0 2/2=1
// 16進数で利用する文字列の配列を渡してしまう。
// sizeはmalloc用の桁数。
// malloc後にfreeすること。
char	*ft_convert(unsigned long n, int base, char *str)
{
	size_t			count;
	unsigned long	tmp;
	char			*p;

	count = 0;
	tmp = n;
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
	if (upper_flag)
		converted = ft_convert(n, 16, "0123456789ABCDEF");
	else
		converted = ft_convert(n, 16, "0123456789abcdef");
	// x, Xの場合、0xを先頭につける必要無し。
	// 先頭に16進数の目印である0xをつける。（先に出力してしまう。）
	// ft_output_s("0x");
	len = ft_output_s(converted);
	// 変換した文字列格納用メモリを解放。
	free(converted);
	return (len);
}

int ft_sort(const char* inputs, va_list input_list)
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

int	ft_printf(const char * inputs, ...)
{
	int	output_len;
    va_list	input_list;
	// mallocをどこで利用するのか要確認。
    va_start(input_list, inputs);
	output_len = ft_sort(inputs, input_list);
    va_end(input_list);
	return (output_len);
}

int main(void)
{
	char	*p;

	p = "address";
	printf("\n=== c ===\n");
	printf("--- ft_printf ---\n");
	int r_ft_c = ft_printf("%c", 'a');
	printf("\nr_ft = %d\n", r_ft_c);
	printf("--- printf ---\n");
	int r_c = printf("%c", 'a');
	printf("\nr = %d\n", r_c);
	
	printf("\n=== s ===\n");
	printf("--- ft_printf ---\n");
	int r_ft_s = ft_printf("%s", "test");
	printf("\nr_ft = %d\n", r_ft_s);
	printf("--- printf ---\n");
	int r_s = printf("%s", "test");
	printf("\nr_ft = %d\n", r_ft_s);
	
	printf("\n=== d ===\n");
	printf("--- ft_printf ---\n");
	int r_ft_d = ft_printf("%d", 1);
	printf("\nr_ft = %d\n", r_ft_d);
	printf("--- printf ---\n");
	int r_d = ft_printf("%d", 1);
	printf("\nr_ft = %d\n", r_d);

	printf("\n=== p ===\n");
	printf("--- ft_printf ---\n");
	int r_ft_p = ft_printf("%p", p);
	printf("\nr_ft = %d\n", r_ft_p);
	printf("--- printf ---\n");
	int r_p = printf("%p", p);
	printf("\nr = %d\n", r_p);

	printf("\n=== i ===\n");
	printf("--- ft_printf ---\n");
	int r_ft_i = ft_printf("%i", 12);
	printf("\nr_ft = %i\n", r_ft_i);
	printf("--- printf ---\n");
	int r_i = printf("%i", 12);
	printf("\nr = %d\n", r_i);

	printf("\n=== u ===\n");
	printf("--- ft_printf ---\n");
	int r_ft_u = ft_printf("%u", 24);
	printf("\nr_ft = %i\n", r_ft_u);
	printf("--- printf ---\n");
	// [] To Do: printfにintの最大値を超えたものを入れると、%ldに変更するようにwarningが出て実行できない。
	int r_u = printf("%u", 24);
	printf("\nr = %d\n", r_u);

	printf("\n=== x ===\n");
	printf("--- ft_printf ---\n");
	int r_ft_x = ft_printf("%x", 12);
	printf("\nr_ft = %i\n", r_ft_x);
	printf("--- printf ---\n");
	int r_x = printf("%x", 12);
	printf("\nr = %d\n", r_x);

	printf("\n=== X ===\n");
	printf("--- ft_printf ---\n");
	int r_ft_X = ft_printf("%X", 12);
	printf("\nr_ft = %i\n", r_ft_X);
	printf("--- printf ---\n");
	int r_X = printf("%X", 12);
	printf("\nr = %d\n", r_X);

	return (0);
}
