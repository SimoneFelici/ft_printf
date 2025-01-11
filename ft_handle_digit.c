#include "ft_printf.h"

int	ft_handle_digit(va_list args)
{
	char	*str;
	int		len;
	int		n;

	n = va_arg(args, int);
	str = ft_itoa(n);
	if (!str)
		return (0);
	len = ft_print_digit(str);
	free(str);
	return (len);
}
