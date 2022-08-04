/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:06:21 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/21 21:16:35 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Delete (del) and (free) memory space of the element(s)++ in param.
Initial ptr (lst) == at NULL
lst: Memory adress of an element.
del: memory adress of the func. that can delete content of an element. 
*/
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*now;

	now = *lst;
	while (now)
	{
		now = now->next;
		ft_lstdelone(*lst, del);
		*lst = now;
	}
	lst = NULL;
}
