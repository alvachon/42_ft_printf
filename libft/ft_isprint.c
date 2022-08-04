/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:14:06 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/18 14:08:16 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Check alnum and nonnum. Good for IF structure */

#include "libft.h"

static int	ft_isnonum(int c)
{
	if ((c >= 040 && c <= 047) || (c >= 050 && c <= 057) || c == 0100
		|| (c >= 072 && c <= 077) || (c >= 0133 && c <= 0140)
		|| (c >= 0173 && c <= 0176))
		return (1);
	else
		return (0);
}

int	ft_isprint(int c)
{
	if (ft_isalnum(c) || ft_isnonum(c))
		return (1);
	else
		return (0);
}
