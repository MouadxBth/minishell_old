/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:00:23 by mbouthai          #+#    #+#             */
/*   Updated: 2023/01/08 20:05:55 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **list, t_list *new, int option)
{
	if (!list)
		return ;
	if (!*list)
	{
		*list = new;
		return ;
	}
	if (option == 0)
		ft_lstadd_back(list, new);
	else
		ft_lstadd_front(list, new);
}
