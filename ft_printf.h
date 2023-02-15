/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubsky <pdubsky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:08:48 by pdubsky           #+#    #+#             */
/*   Updated: 2023/02/15 17:08:49 by pdubsky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf_c(int c);
int	ft_printf_str(char *str);
int	ft_printf_ptr(unsigned long long ptr);
int	ft_printf_int(long long i);
int	ft_get_format(char format, va_list args);
int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_print_hex(unsigned int num, const char format);

#endif
