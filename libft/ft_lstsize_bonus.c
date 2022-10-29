/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:11:46 by mbouthai          #+#    #+#             */
/*   Updated: 2022/01/27 16:13:13 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		length;
	t_list	*temp;

	length = 0;
	temp = lst;
	while (temp)
	{
		length++;
		temp = temp->next;
	}
	return (length);
}
