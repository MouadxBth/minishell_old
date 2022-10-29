/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:28:33 by mbouthai          #+#    #+#             */
/*   Updated: 2022/02/20 14:23:01 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	index;
	size_t	length;

	if (!s)
		return ;
	index = 0;
	length = ft_strlen(s);
	while (index < length)
	{
		f(index, &s[index]);
		index++;
	}
}
