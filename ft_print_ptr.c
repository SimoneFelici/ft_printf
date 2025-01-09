#include "ft_printf.h"

void print_ptr(void *ptr)
{
	int i;
	uintptr_t uptr;

	if (!ptr)
		write(1, "(nil)", 5);
	uptr = (uintptr_t)ptr;
	char *hex = ft_ulltoa_base(uptr, "0123456789abcdef");
	if (!hex)
		return ;
	write(1, "0x", 2);
	i = 0;
	while (hex[i])
	{
		write(1, &hex[i], 1);
		i++;
	}
	free(hex);
}
