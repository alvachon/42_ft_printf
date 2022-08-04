/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:12:53 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/21 21:45:23 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Return a chain of character with malloc the same as s1, but without element
of set.
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*mem;

	if (s1 != 0 && set != 0)
	{
		start = 0;
		end = ft_strlen(s1);
		while (s1[start] && ft_strchr(set, s1[start]))
			start++;
		while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > start)
			end--;
		mem = (char *)malloc(sizeof(char) * ((end - start) + 1));
		if (mem)
			ft_strlcpy(mem, &s1[start], (end - start) + 1);
		return (mem);
	}
	return (0);
}
