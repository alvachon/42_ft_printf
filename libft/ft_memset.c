/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:14:54 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/18 14:11:41 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Fill block of memory (first argument) with a determined unsigned char item */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*mem;

	mem = b;
	while (len > 0)
	{
		*mem = (unsigned char)c;
		mem++;
		len--;
	}
	return (b);
}
