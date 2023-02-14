#include "ft_printf.h"

int ft_printf_str(char *str)
{
    size_t i;
    i = 0;
    if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}

    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}