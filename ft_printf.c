#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

void	print_char(char c)
{
	write(1, &c, 1);
}

void	print_str(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_digit(const char *str)
{
	int i;
	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		done;

	i = 0;
	done = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			if (format[i] == 'c')
			{
				char c = (char)va_arg(args, int);
				print_char(c);
				done++;
			}
			else if (format[i] == 's')
			{
				char *s = va_arg(args, char *);
				print_str(s);
				done+= ft_strlen(s);
			}
			else if (format[i] == 'd')
			{
				int n = va_arg(args, int);
				char *d = ft_itoa(n);
				print_digit(d);
				done += ft_strlen(d);
				free(d);
			}
			else
			{
				print_char(format[i]);
				done++;
			}
			}
		else
		{
			print_char(format[i]);
			done++;
		}
		i++;
	}
	va_end(args);
	return done;
}


int main(void)
{
	ft_printf("Hello %c!\n", 'A');
	ft_printf("Numero: %d\n", 42);
	ft_printf("Stringa: %s\n", "Ciao Mondo");

	ft_printf("%d\n", ft_printf("Numero: %d\n", 42));
	return (0);
}
