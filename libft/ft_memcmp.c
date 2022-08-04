/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 23:10:54 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/18 14:51:36 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 	Return 0 if two strings are identical. 
	Return > 0 if s1 longer. 
	Return < 0 if s2 longer
	Both strings are assumed to be n bytes long 
	Treated as unsigned char values, so that `\200' is greater than `\0'*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ps1;
	const unsigned char	*ps2;

	ps1 = s1;
	ps2 = s2;
	while (n != 0)
	{
		if (*ps1++ != *ps2++ && n)
			return (*--ps1 - *--ps2);
		--n;
	}
	return (0);
}
