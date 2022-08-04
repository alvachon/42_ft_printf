/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:05:48 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/18 14:44:52 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Compare the null-terminated strings s1 and s2 no more than N character */
/* After '\0' = Not compared */
/* return an int >, =, or < than 0, string s1 to  string s2.
 * The comparison is done using unsigned char, so that `\200' > than `\0'.*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	i = 0;
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (ps1[i] == ps2[i] && ps1[i] != '\0' && ps2[i] != '\0'
		&& i < (n - 1))
		i++;
	return (ps1[i] - ps2[i]);
}
