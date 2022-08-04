/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 08:43:48 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/22 13:36:37 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Iteration.
Applies the function f on each char element of the string of char as arg.
Each char is given the adress directly by 'f' ton transform if necessary.
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
