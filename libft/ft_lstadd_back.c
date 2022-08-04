/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:04:58 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/21 21:11:53 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Add New Element at the end of the list.
lst: memory adress of the first element of the list;
new: memory adress of the new element to add.
*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}
