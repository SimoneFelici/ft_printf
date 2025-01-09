#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
char	*ft_uitoa(unsigned int n);
char	*ft_uitoa_base(unsigned int n, const char *base_str);
char	*ft_ulltoa_base(unsigned long long n, const char *base_str);

#endif
