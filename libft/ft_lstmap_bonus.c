/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:21:44 by mbouthai          #+#    #+#             */
/*   Updated: 2022/02/18 14:00:35 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*current_node;
	t_list	*next_node;

	if (!lst || !f)
		return (0);
	result = ft_lstnew(f(lst->content));
	if (!result)
		return (0);
	current_node = result;
	lst = lst->next;
	while (lst)
	{
		next_node = ft_lstnew(f(lst->content));
		if (!next_node)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		current_node->next = next_node;
		current_node = next_node;
		lst = lst->next;
	}
	return (result);
}
