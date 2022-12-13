#include "printf.h"

static int  ft_get_format(char param, va_list args)
{
    if (param == 'c')
        return (ft_printf_c(va_arg(args, int)));
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
    ft_printf("hey");
}