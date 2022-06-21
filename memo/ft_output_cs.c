
# include "printf.h"

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