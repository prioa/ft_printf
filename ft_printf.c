# include "printf.h"
# include <stdarg.h>
# include <unistd.h>


int	ft_print_c(int c)
{
	write(1, &c, 1);
	return (1);
}

char ft_print_str(char *str)
{
    size_t  i;

    if (str == 0)
    {
        write(1, "(null)", 6);
        return (6);
    }
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}

static int  ft_get_format(char format, va_list args)
{
    if (format == 'c')
        return (ft_print_c(va_arg(args, int)));
    else if (format == 's')
        return (ft_print_str(va_arg(args, char *)));
    else if (format == '%')
        write(1, "%", 1);

    else
        return (0);
}

int ft_printf(const char *str, ...)
{
    size_t  i;
    int res;
    va_list args;


    i = 0;
    res = 0;
    va_start(args, str);
    while(str[i])
    {
        if (str[i] == '%')
        {
            res += ft_get_format(str[i+1], args);
            i++;
        }
        else
            res += write(1, &str[i], 1);
        i++;
    }
    va_end(args);
    return (res);
}

int main()
{
    int c = 'x';
    char *str = " hallo bist du dumm ";
    ft_printf("%s ey %c", str, c);
    write(1, "\n", 2);
}