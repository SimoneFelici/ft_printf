#include "ft_printf.h"

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
	char	*s;

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
				s = va_arg(args, char *);
				if (!s)
					s = "(null)";
				print_str(s);
				done += ft_strlen(s);
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				int n = va_arg(args, int);
				s = ft_itoa(n);
				print_digit(s);
				done += ft_strlen(s);
				free(s);
			}
			else if (format[i] == 'u')
			{
				unsigned int un = va_arg(args, unsigned int);
				s = ft_uitoa(un);
				if (s)
				{
				print_digit(s);
				done += ft_strlen(s);
				free(s);
				}
			}
			else if (format[i] == 'x')
			{
				unsigned int un = va_arg(args, unsigned int);
				s = ft_uitoa_base(un, "0123456789abcdef");
				if (s)
				{
					print_digit(s);
					done += ft_strlen(s);
					free(s);
				}
			}
			else if (format[i] == 'X')
			{
				unsigned int un = va_arg(args, unsigned int);
				s = ft_uitoa_base(un, "0123456789ABCDEF");
				if (s)
				{
					print_digit(s);
					done += ft_strlen(s);
					free(s);
				}
			}
			else if (format[i] == 'p')
			{
				unsigned long long addr = va_arg(args, unsigned long long);
				if (addr == 0)
				{
					print_str("(nil)");
					done += 5;
				}
				else
				{
					print_str("0x");
					done += 2;
					s = ft_ulltoa_base(addr, "0123456789abcdef");
					print_str(s);
					done += ft_strlen(s);
					free(s);
				}
			}
			else if (format[i] == '%')
			{
				write(1, "%", 1);
				done++;
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

/*
int main(void)
{
    int   a = 42;
    char *b = "Hello pointers";
    void *null_ptr = NULL;

    ft_printf("Valore di &a: %p\n", &a);
    ft_printf("Valore di b: %p\n", b);
    ft_printf("Puntatore NULL: %p\n", null_ptr);

    printf("Valore di &a: %p\n", &a);
    printf("Valore di b: %p\n", b);
    printf("Puntatore NULL: %p\n", null_ptr);

    return 0;
}
*/
