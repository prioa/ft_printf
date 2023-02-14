#include "ft_printf.h"
#include <stdio.h>

int ft_get_format(char format, va_list args)
{
    int result;

    result = 0;
    if (format == 'c')
        result += ft_printf_c(va_arg(args, int));
    else if (format == 's')
        result += ft_printf_str(va_arg(args, char *));
    else if (format == 'p')
		result += ft_printf_ptr(va_arg(args, unsigned long long));
    else if (format == 'd' || format == 'i')
        result += ft_printf_int(va_arg(args, int));
    else if (format == 'u')
		result += ft_printf_int(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		result += ft_print_hex(va_arg(args, unsigned int), format);

    else if (format == '%')
        result += write(1, "%", 1);
    return (result);
}

int ft_printf(const char *str, ...)
{
    int i;
    int output;
    va_list args;

    i = 0;
    output = 0;
    va_start(args, str);
    while (str[i])
    {
        if (str[i] == '%'){
            output += ft_get_format(str[i+1], args);
            i += 2;
        }else
            output += write(1, &str[i++], 1);
    }
    va_end(args);
    return (output);
}

// int main(){
//     ft_printf(" %c ", '0');
//     printf(" %c ", '0');
//     write(1, "\n", 1);
// }