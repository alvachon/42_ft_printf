/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 12:55:57 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/18 15:52:44 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*locates the first occurrence of c (converted to a char) in the string
 * pointed to by s. The terminating null character is considered to be part of
 * the string; therefore if c is `\0', the functions locate the `\0'. */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}
