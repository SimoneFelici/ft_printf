#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		done;

	va_start(args, format);
	i = 0;
	done = 0;
	while (format && format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			done += ft_handle_format(format[i], args);
		}
		else
		{
			done += ft_print_char(format[i]);
		}
		i++;
	}
	va_end(args);
	return (done);
}
