/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:27:57 by alvachon          #+#    #+#             */
/*   Updated: 2022/07/25 13:39:57 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_set_percent(t_print *flag)
{
	flag->percent = 1;
	flag->width = 1;
	flag->padding = '%';
	flag->pad_front = 1;
	return (2);
}

int	ft_set_padding(const char *format, t_print *flag)
{
	if (*format == '#')
	{
		flag->pad_front = 1;
		flag->padding = '0';
	}
	if (*format == '-')
	{
		flag->pad_end = 1;
		flag->padding = ' ';
	}
	if (*format == '0')
	{
		flag->padding = '0';
		flag->pad_front = 1;
	}
	if (flag->pad_front == 1 || flag->pad_end == 1)
		return (1);
	return (0);
}

int	ft_set_star(t_print *flag, va_list ap)
{
	flag->pad_front = 1;
	flag->padding = ' ';
	flag->width = va_arg(ap, int);
	return (1);
}

int	ft_set_front(t_print *flag)
{
	flag->padding = ' ';
	flag->pad_front = 1;
	flag->digit = 1;
	return (1);
}
