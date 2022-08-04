/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:15:12 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/18 14:13:43 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Erase Block of MEM the size of Buffer. Ex: &adrr, sizeof(struct addr) */
/*If n is zero, bzero() does nothing. */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (!(n == 0))
		ft_memset(s, '\0', n);
}
