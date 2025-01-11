#include "ft_printf.h"

int	ft_handle_hex(va_list args, const char *base)
{
	unsigned int	un;
	char			*str;
	int				len;

	un = va_arg(args, unsigned int);
	str = ft_uitoa_base(un, base);
	if (!str)
		return (0);
	len = ft_print_digit(str);
	free(str);
	return (len);
}
