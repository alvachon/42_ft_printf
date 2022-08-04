/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 09:35:50 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/21 21:32:55 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Join two strings together with malloc. NULL if echec. 
*/
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 && s2)
	{
		i = 0;
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		str = (char *)malloc(sizeof(char) * len_s1 + len_s2 + 1);
		if (str == NULL)
			return (NULL);
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		i = 0;
		while (s2[i] != '\0')
			str[len_s1++] = s2[i++];
		str[len_s1] = '\0';
		return (str);
	}
	return (NULL);
}
