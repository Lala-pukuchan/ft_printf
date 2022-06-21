/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:20:46 by rukobaya          #+#    #+#             */
/*   Updated: 2022/06/20 20:57:43 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "printf.h"

int	ft_printf(const char * inputs, ...)
{
	int	output_len;
    va_list	input_list;
    va_start(input_list, inputs);
	output_len = ft_sort(inputs, input_list);
    va_end(input_list);
	return (output_len);
}

/*int main(void)
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
	printf("\nr_ft = %d\n", r_s);
	
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
}*/
