/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:31:01 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/19 11:32:54 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strrchr() function is identical to strchr(), except it locates the
     last occurrence of c*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				j;
	unsigned char	ch;

	i = 0;
	j = 0;
	ch = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			j = i;
		i++;
	}
	if (s[i] == '\0' && ch == 0)
		return ((char *)s + i);
	else if (j > 0 || (j == 0 && s[j] == ch))
		return ((char *)s + j);
	return (NULL);
}
