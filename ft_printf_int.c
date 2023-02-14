#include "ft_printf.h"

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

void	ft_putnbr(unsigned long long i)
{
	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
		ft_putchar(i + '0');
}


int ft_printf_int(long long i)
{
	int	counter;

	if (i < 0)
	{
		counter = 1;
		write(1, "-", 1);
		i = i * -1;
	}
	else
		counter = 0;
	if (i == 0)
		counter++;
	ft_putnbr(i);
	while (i != 0)
	{
		counter++;
		i /= 10;
	}
	return (counter);
}