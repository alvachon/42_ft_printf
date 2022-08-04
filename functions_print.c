/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:53:56 by alvachon          #+#    #+#             */
/*   Updated: 2022/07/25 15:51:43 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_width(t_print *flag)
{
	int	i;

	i = 0;
	if (flag->digit == 1 && flag->percent == 0)
	{
		if ((flag->arg == 1 && flag->width < 3) || flag->width <= flag->len_str)
		{
			flag->width = 0;
			return (0);
		}
		i = flag->width - flag->len_str;
		if (flag->hex == 1)
			i = i - 2;
		while (i != 0)
		{
			write(1, &flag->padding, 1);
				i--;
		}
		return (0);
	}
	return (0);
}

int	ft_print_front_padding(t_print *flag)
{
	int	printed;

	printed = 0;
	if (flag->pad_front == 1 && flag->percent == 0)
		printed = ft_print_width(flag);
	if (flag->dec_sign == 1)
	{
		write(1, "+", 1);
		printed++;
	}
	if (flag->hex == 1)
	{
		write(1, "0x", 2);
		printed += 2;
	}
	if (flag->percent == 1)
		write(1, "%", 1);
	return (printed);
}

int	ft_print_arg(t_print *flag)
{
	if (flag->c == 1)
	{
		write(1, &flag->alph, 1);
		return (flag->len_str + 1);
	}
	if (flag->arg == 1)
	{
		write(1, flag->str, flag->len_str);
		if (flag->digit == 1 && flag->hex == 1)
			return (flag->width);
		if (flag->digit == 1 && flag->width <= 2)
			return (flag->len_str - flag->width);
		if (flag->digit == 1 && flag->width > 2)
			return (0);
		if (flag->alloc == 1)
			free(flag->str);
		return (flag->len_str);
	}
	return (0);
}

int	ft_print_end_padding(t_print *flag)
{
	if (flag->pad_end == 1 && flag->pad_front == 0)
		ft_print_width(flag);
	return (flag->width);
}
