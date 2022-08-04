/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:02:54 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/18 14:18:03 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Copy/Paste *str of a block of MEMbyte to an other MEM in the dst. Deal 
Overlap. Return dst from MEM start w/modifications. Does NOT check NULL char 
in orignal function. */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_m;
	char		*src_m;
	size_t		i;

	i = 0;
	dst_m = (char *)dst;
	src_m = (char *)src;
	if ((dst == src || len == 0))
		return (dst);
	if (dst_m > src_m)
		while (len-- > 0)
			dst_m[len] = src_m[len];
	else
	{
		while (i < len)
		{
			dst_m[i] = src_m[i];
			i++;
		}
	}
	return (dst);
}
