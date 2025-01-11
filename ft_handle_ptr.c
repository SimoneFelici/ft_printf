#include "ft_printf.h"

int	ft_handle_ptr(va_list args)
{
	unsigned long long	addr;
	char				*str;
	int					len;

	addr = va_arg(args, unsigned long long);
	if (addr == 0)
	{
		return (ft_print_str("(nil)"));
	}
	str = ft_ulltoa_base(addr, "0123456789abcdef");
	if (!str)
		return (0);
	ft_print_str("0x");
	len = ft_print_str(str);
	free(str);
	return (len + 2);
}
