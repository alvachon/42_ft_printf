/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:05:34 by alvachon          #+#    #+#             */
/*   Updated: 2022/05/21 21:20:59 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Free Memory of the element in arg. While using del function and free. 
memory of next should'nt be free. 
lst: Element to free
del: Memory adress that can delete the content of the element. 
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
	return ;
}
