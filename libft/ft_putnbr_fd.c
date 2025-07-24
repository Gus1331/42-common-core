
#include "libft.h"

void ft_putnbr_fd(int n, int fd);

void ft_putnbr_fd(int n, int fd)
{
    char output;

    output = '0';
    if (n >= 10)
        ft_putnbr_fd(n / 10, fd);
    output += (n %10);
    write(fd, &output, 1);
}
