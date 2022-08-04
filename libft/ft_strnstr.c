/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:21:19 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/18 22:19:23 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Locates the first str needle (and null-terminate it) in the string haystack,
 * Where not more than len characters are searched. (include or before ?)
 * Characters that appear after a `\0' character are not searched.//
 * If needle is an empty string, haystack is returned //
 * If needle occurs nowhere in haystack, NULL is returned//
 * Otherwise a pointer to the first character of the first occurrence of needle
 * is returned.*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack + i);
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			while (haystack[i + j] == needle[j] && (i + j) < len \
			&& haystack[i + j] != '\0')
				j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
