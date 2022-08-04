/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 09:12:11 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/18 15:42:56 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates sufficient memory for a copy of the string s1, does the copy, and
 *returns a pointer to it.The pointer may subsequently be used as an argument
 to the function free(3).*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * len + 1);
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy, s1, len);
	copy[len] = '\0';
	return (copy);
}
