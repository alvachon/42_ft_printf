/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:02:51 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/21 21:13:19 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Add new element in front of the list.
lst: Memory adress of the first element of the list.
new: Memory adress of new element to add in front. 
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
	return ;
}
