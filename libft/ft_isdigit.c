/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:13:10 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/18 14:05:42 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Check if digit. Good for IF structure */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 0 && c <= 127)
	{
		if (c >= '0' && c <= '9')
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
