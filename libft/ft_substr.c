/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 09:20:28 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/21 21:46:17 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Alloc a part of a chain of character from *s.
*/

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*mem;
	size_t	len_s;

	if (s)
	{
		len_s = ft_strlen(s);
		if (len_s < start)
		{
			mem = ft_calloc(1, sizeof(char));
			if (!mem)
				return (NULL);
			mem[0] = '\0';
			return (mem);
		}
		if (len_s < len)
			len = len_s;
		mem = ft_calloc(len + 1, sizeof(char));
		if (!mem)
			return (NULL);
		ft_memcpy(mem, &s[start], len);
		mem[len] = '\0';
		return (mem);
	}
	return (NULL);
}
