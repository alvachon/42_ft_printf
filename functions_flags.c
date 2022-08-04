/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:46:38 by alvachon          #+#    #+#             */
/*   Updated: 2022/08/01 15:50:23 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_reset(const char *format, t_print *flag)
{
	flag->str = "0";
	flag->len_str = 1;
	flag->alloc = 0;
	if (*format == 'p')
	{
		flag->hex = 1;
	}
}

int	ft_set_specifier(const char *format, t_print *flag, va_list ap)
{
	int	i;

	i = 0;
	if (format[i] == 's' && flag->percent == 0)
		i += ft_set_s(flag, ap);
	else if (format[i] == 'c' && flag->percent == 0)
		i += ft_set_c(flag, ap);
	else if ((format[i] == 'x' || format[i] == 'X' || format[i] == 'p') && \
		flag->percent == 0)
		i += ft_set_xxp(format, flag, ap);
	else if ((format[i] == 'd' || format[i] == 'i' || format[i] == 'u') && \
		flag->percent == 0)
		i += ft_set_diu(format, flag, ap);
	return (i);
}

int	ft_set_width(const char *format, t_print *flag, va_list ap)
{
	int	i;

	i = 0;
	if (format[i] == '%')
	{
		i++;
		if (format[i] == '%' && format[i - 1] == '%')
			return (ft_set_percent(flag));
		i += ft_set_padding(format, flag);
		if (format[i] == '*')
			i += ft_set_star(flag, ap);
		else if (ft_isdigit(format[i]))
		{
			flag->width = ft_atoi(&format[i]);
			i += ft_set_front(flag);
			while (ft_isdigit(format[i]) || format[i] == '-')
				i++;
		}
		return (i);
	}
	return (0);
}

int	ft_set_precision(const char *format, t_print *flag, va_list ap)
{
	int	i;

	i = 0;
	if (format[i] == '.')
	{
		i++;
		flag->precision = 1;
		if (format[i] == '*')
		{
			flag->len_precision = va_arg(ap, int);
			i++;
		}
		else if (ft_isdigit(format[i]))
		{
			flag->len_precision = ft_atoi(format);
			while (ft_isdigit(format[i]) || format[i] == '-')
				i++;
		}
	}
	i = i + ft_set_specifier(&format[i], flag, ap);
	return (i);
}
