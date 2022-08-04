/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:35:10 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/22 13:42:11 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Return an array of strings that was separated by (char c)
Need to be finished by NULL;
*/
#include "libft.h"

static char	*ft_strndup(const char *s, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = NULL;
	if (len == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**ft_freeall(char **list)
{
	size_t	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (NULL);
}

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	array_size;
	size_t	i;

	i = 0;
	array_size = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || \
		(s[i] == c && s[i + 1] != '\0' && s[i + 1] != c))
			array_size++;
		i++;
	}
	return (array_size);
}

char	**ft_split(char const *s, char c)
{
	char	**str_array;
	size_t	index;
	size_t	len_str;
	size_t	len_start;

	index = 0;
	len_str = 0;
	str_array = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (str_array && s)
	{
		while (index < ft_wordcount(s, c) && s[len_str] != '\0')
		{
			while (s[len_str] == c)
				len_str++;
			len_start = len_str;
			while (s[len_str] != c && s[len_str] != '\0')
				len_str++;
			str_array[index] = ft_strndup(&s[len_start], len_str - len_start);
			if (str_array[index++] == 0)
				return (ft_freeall(str_array));
		}
		str_array[index] = NULL;
		return (str_array);
	}
	return (NULL);
}
