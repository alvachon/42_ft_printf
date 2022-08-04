/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:50:10 by alvachon          #+#    #+#             */
/*   Updated: 2022/07/23 12:18:17 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_init_flag(t_print *flag)
{
	flag->padding = '\0';
	flag->pad_front = 0;
	flag->pad_end = 0;
	flag->width = 0;
	flag->hex = 0;
	flag->dec_sign = 0;
	flag->len_str = 0;
	flag->precision = 0;
	flag->len_precision = 0;
	flag->c = 0;
	flag->alph = '\0';
	flag->str = "\0";
	flag->alloc = 0;
	flag->arg = 0;
	flag->modifier = 0;
	flag->percent = 0;
	flag->zero_pacing = 0;
	flag->digit = 0;
}

int	ft_check_flag(const char *format, t_print *flag, va_list ap)
{
	int	i;

	i = 0;
	if (*format == '%')
	{
		i += ft_set_width(format, flag, ap);
		i += ft_set_precision(&format[i], flag, ap);
		return (i);
	}
	return (0);
}

int	ft_check_format(const char *format, va_list ap)
{
	int		i;
	int		printed;
	t_print	flag;

	i = 0;
	printed = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_init_flag(&flag);
			i += ft_check_flag(&format[i], &flag, ap);
			printed += ft_print_front_padding(&flag);
			printed += ft_print_arg(&flag);
			printed += ft_print_end_padding(&flag);
		}
		else if (format[i] != '%')
		{
			write(1, &format[i++], 1);
			printed++;
		}
	}
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		printed;

	va_start(ap, format);
	printed = ft_check_format(format, ap);
	va_end (ap);
	return (printed);
}
