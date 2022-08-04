/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:18:11 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/18 14:27:20 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Copies up to dstsize -1 characters from the string src to dst, 
 * NUL-terminating the result if dstsize is not 0.
 * Return the total length of the string src.
 *
 * If the return value is >= dstsize, the output string has been truncated.
 * It is the caller's responsibility to handle this. 
 *
 * Behavior Undefined if Overlap.*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (srcsize + 1 < dstsize)
		ft_memcpy(dst, src, srcsize + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize -1] = '\0';
	}
	return (srcsize);
}
