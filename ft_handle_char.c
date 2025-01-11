#include "ft_printf.h"

int	ft_handle_char(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	return (ft_print_char(c));
}
