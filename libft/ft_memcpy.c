/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:12:53 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/18 14:16:24 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Copy/Paste a buffer of *str in MEM. Don't deal overlap (behavior undefined)
	Does not check NULL char. Return original value of dst. */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_m;
	const char	*src_m;

	dst_m = dst;
	src_m = src;
	if ((dst != 0) || (src != 0))
	{
		while (n--)
			*dst_m++ = *src_m++;
	}
	return (dst);
}
