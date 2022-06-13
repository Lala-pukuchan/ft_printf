/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:20:46 by rukobaya          #+#    #+#             */
/*   Updated: 2022/06/14 07:58:25 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// delete later
#include <stdio.h>
#include <assert.h>

#include <stdarg.h> // va_list

int ft_divide(const char* inputs, va_list input_list)
{
	int	invalid_type;

	invalid_type = 0;
	while (*inputs)
	{
		while (*inputs)
		printf("input = %c", *inputs);
	}
		
	/*for (const char* p = format; *p != '\0'; ++p){
        switch(*p){
			case 'd':
				printf( "%d ", va_arg(args, int) );
				break;
			case 'f':
				printf( "%f ", va_arg(args, double) );
				break;
			case 'c':
				printf( "%c ", va_arg(args, int) );
				break;
			case 's':
				printf( "%s ", va_arg(args, const char*) );
				break;
			default:
				assert( !"不正な変換指定" );
				break;
        }
    }*/
	return (0);
}

int	ft_printf(const char * inputs, ...)
{
	int	output_len;
    va_list	input_list;

    va_start(input_list, inputs);
	output_len = ft_divide(inputs, input_list);
    printf("\n");
    va_end(input_list);
	return (output_len);
}

int main(void)
{
	printf("--- ft_printf ---\n");
	int r_ft = ft_printf("%s\n", "test");
	printf("r_ft = %d\n", r_ft);

	printf("--- printf ---\n");
	int r = printf("%s\n", "test");
	printf("r = %d\n", r);
	return (0);
}
