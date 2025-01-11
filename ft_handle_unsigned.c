#include "ft_printf.h"

int	ft_handle_unsigned(va_list args)
{
	unsigned int	un;
	char			*str;
	int				len;

	un = va_arg(args, unsigned int);
	str = ft_uitoa(un);
	if (!str)
		return (0);
	len = ft_print_digit(str);
	free(str);
	return (len);
}
