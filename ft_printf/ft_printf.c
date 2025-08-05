// Insert 42 HEADER

#include "libft.h"
#include <stdarg.h>

int			ft_printf(const char *format, ...);
static int	count_args(const char *format);

static int	count_args(const char *format)
{
	int	count;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (++*format == '%')
				count++;
		}
		format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		arg_count;
	int		print_count;
	
	arg_count = count_args(format);
	va_start(args, format);
	if (!arg_count)
	{
		ft_putstr_fd(format, 1);
	}
	va_end(args);
	return (0);
}

int main (void){
	ft_printf("Hello Word");
	return (0);
}
