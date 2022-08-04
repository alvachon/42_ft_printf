/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:09:41 by alvachon          #+#    #+#             */
/*   Updated: 2022/08/01 15:50:21 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_check_len_mod(t_print *flag)
{
	if (!flag->len_precision || flag->len_precision == 0)
		flag->len_precision = 1;
	if (flag->len_str < flag->len_precision)
	{
		flag->pad_front = 1;
		flag->padding = '0';
		flag->width = flag->len_precision - flag->len_str;
	}
}

int	ft_set_s(t_print *flag, va_list ap)
{	
	flag->arg = 1;
	flag->s = 1;
	flag->str = va_arg(ap, char *);
	if (flag->str == NULL)
		flag->str = "(null)";
	if (flag->precision == 1 && flag->len_str > flag->len_precision)
			flag->len_str = flag->len_precision;
	flag->len_str = ft_strlen((const char *)flag->str);
	return (1);
}

int	ft_set_c(t_print *flag, va_list ap)
{
	flag->c = 1;
	flag->arg = 0;
	flag->alph = va_arg(ap, int);
	return (1);
}

int	ft_set_xxp(const char *format, t_print *flag, va_list ap)
{
	unsigned long	num;

	num = va_arg(ap, unsigned long);
	flag->alloc = 1;
	flag->arg = 1;
	if (flag->padding == '0' && flag->pad_end == 1)
		flag->pad_front = 0;
	if (num && *format == 'x')
		flag->str = ft_deal_hexa(num, 0);
	if (num && *format == 'X')
		flag->str = ft_deal_hexa(num, 16);
	flag->len_str = ft_strlen((const char *)flag->str);
	if (flag->precision == 1)
		ft_check_len_mod(flag);
	if (num && *format == 'p')
	{
		flag->hex = 1;
		flag->str = ft_deal_ptr(num);
		flag->len_str = ft_strlen((const char *)flag->str);
	}
	if (!num)
		ft_reset(format, flag);
	return (1);
}

int	ft_set_diu(const char *format, t_print *flag, va_list ap)
{
	unsigned long	num;

	num = 0;
	flag->arg = 1;
	flag->alloc = 1;
	if ((*format == 'd' || *format == 'i'))
	{
		num = va_arg(ap, int);
		if (num)
			flag->str = ft_itoa(num);
	}
	if (*format == 'u')
	{
		num = va_arg(ap, unsigned int);
		if (num)
			flag->str = ft_deal_usign(num);
	}
	flag->len_str = ft_strlen((const char *)flag->str);
	if (flag->precision == 1)
		ft_check_len_mod(flag);
	if (!num)
		ft_reset(format, flag);
	return (1);
}
