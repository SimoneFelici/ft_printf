#include "ft_printf.h"

int	ft_handle_str(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		return (ft_print_str("(null)"));
	return (ft_print_str(str));
}
