#include "ft_printf.h"

int	ft_ptr_len(uintptr_t n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

void	ft_put_ptr(uintptr_t n)
{
	if (n >= 16)
	{
		ft_put_ptr(n / 16);
		ft_put_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_printf_c(n + '0');
		else
			ft_printf_c((n - 10) + 'a');
	}
}

int	ft_printf_ptr(unsigned long long ptr)
{
	int	result;

	result = 0;
	if (ptr == 0){
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		result = 0;
		result += write(1, "0x", 2);
		ft_put_ptr(ptr);
		result += ft_ptr_len(ptr);
	}
	return (result);
}
