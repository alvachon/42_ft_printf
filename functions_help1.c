/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_help1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:51:50 by alvachon          #+#    #+#             */
/*   Updated: 2022/07/22 11:57:21 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static unsigned int	ft_ptoa_len(unsigned long n)
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

static unsigned int	ft_utoa_len(unsigned int n)
{
	unsigned int	a;

	if (n == 0)
		return (1);
	a = 0;
	while (n != 0)
	{
		a += 1;
		n = n / 10;
	}
	return (a);
}

char	*ft_deal_ptr(unsigned long n)
{
	char	*temp;
	char	*digits;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_ptoa_len(n);
	digits = "0123456789abcdef";
	temp = (char *)malloc(sizeof(char) * len + 1);
	if (!temp)
		return (NULL);
	temp[len] = '\0';
	while (n != 0)
	{
		temp[len - 1] = digits[n % 16];
		n = n / 16;
		len--;
	}
	return (temp);
}

char	*ft_deal_usign(unsigned int n)
{
	char			*temp;
	unsigned int	len;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_utoa_len(n);
	temp = (char *)malloc(sizeof(char) * len + 1);
	if (!temp)
		return (NULL);
	temp[len] = '\0';
	while (n != 0)
	{
		temp[--len] = (n % 10) + '0';
		n = n / 10;
	}
	return (temp);
}
