/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:30:38 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/19 11:59:49 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Take the full size of dstsize and guarantee NUL-termination if room.
 * Note that room for the NUL should be included in dstsize.
 * strlcat() appends string src to the end of dst.
 * It will append at most dstsize - strlen(dst) - 1 characters.
 * It will then NUL-terminate, unless  dstsize is 0 or the original dst string
 * was longer than dstsize (in practice this should not happen as it means that
 * either dstsize is incorrect or that dst is not a proper string).
 *
 * If the src and dst strings overlap, the behavior is undefined*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (dstsize <= len_dest)
		return (len_src + dstsize);
	while (src[i] && len_dest + i < dstsize - 1)
	{
		dst[len_dest + i] = src[i];
		i++;
	}
	dst[len_dest + i] = '\0';
	return (len_src + len_dest);
}
