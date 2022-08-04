/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:22:52 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/18 14:06:00 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Check Alpha & Digit. Good for IF stucture. */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c >= 0 && c <= 127)
	{
		if (ft_isalpha(c) || ft_isdigit(c))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
