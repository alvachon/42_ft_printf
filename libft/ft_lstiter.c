/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:07:16 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/21 21:20:53 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Iteration on linked list 'lst' and apply function f on each elements.
lst: Memory adress of an element.
f: Memory adress of a function to activate the iteration.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst || f)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
	return ;
}
