/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:07:38 by mbouthai          #+#    #+#             */
/*   Updated: 2022/01/27 16:09:23 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*temp;

	temp = (t_list *) malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
	temp->content = content;
	temp->next = NULL;
	return (temp);
}
