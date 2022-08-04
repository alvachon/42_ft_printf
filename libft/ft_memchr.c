/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:36:14 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/18 15:44:15 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The memchr() function locates the first occurrence of c (converted to an 
 * unsigned char) in string s. The memchr() function returns a pointer to the
 * byte located, or NULL if no such byte exists within n bytes. Strchr seems
 * to be better */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*str;
	int				i;

	ch = c;
	str = (unsigned char *)s;
	i = 0;
	while (n)
	{
		if (str[i] == ch)
			return (&str[i]);
		i++;
		n--;
	}
	return (NULL);
}
