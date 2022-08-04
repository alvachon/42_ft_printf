/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_help2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:57:26 by alvachon          #+#    #+#             */
/*   Updated: 2022/07/22 11:58:01 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static unsigned int	ft_xtoa_len(unsigned int n)
{
	unsigned int	a;

	if (n == 0)
		return (0);
	a = 0;
	while (n != 0)
	{
		n = n / 16;
		a++;
	}
	return (a);
}

char	*ft_deal_hexa(unsigned int n, int capitals)
{
	char				*temp;
	char				*digits;
	unsigned int		len;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_xtoa_len(n);
	digits = "0123456789abcdef0123456789ABCDEF";
	temp = (char *)malloc(sizeof(char) * len + 1);
	if (!temp)
		return (NULL);
	temp[len] = '\0';
	while (n != 0)
	{
		temp[len -1] = digits[(n % 16) + capitals];
		n = n / 16;
		len--;
	}
	return (temp);
}
