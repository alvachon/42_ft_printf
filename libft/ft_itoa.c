/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 08:25:45 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/21 21:27:14 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* return in int number a chain of character */

#include "libft.h"

static int	ft_nb_len(int nb)
{
	long	n;
	int		i;

	i = 0;
	n = nb;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		i;

	nb = n;
	i = ft_nb_len(n) - 1;
	str = (char *)malloc(sizeof(char) * (ft_nb_len(n) + 1));
	if (str == 0)
		return (NULL);
	if (n == -2147483648)
		nb = 2147483648;
	else if (nb < 0)
		nb = nb * -1;
	str[ft_nb_len(n)] = '\0';
	while (i >= 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
