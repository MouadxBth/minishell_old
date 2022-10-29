/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:40:57 by mbouthai          #+#    #+#             */
/*   Updated: 2022/01/22 22:36:14 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	second_index;

	if (!*little)
		return ((char *)big);
	index = 0;
	while (big[index])
	{
		if (big[index] == little[0])
		{
			second_index = 0;
			while (little[second_index] && index + second_index < len)
			{
				if (big[index + second_index] != little[second_index])
					break ;
				second_index++;
			}
			if (!little[second_index])
				return ((char *) big + index);
		}
		index++;
	}
	return (NULL);
}	
