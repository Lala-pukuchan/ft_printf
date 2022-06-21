
# include "printf.h"

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
