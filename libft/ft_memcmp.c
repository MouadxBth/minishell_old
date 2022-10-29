/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:48:04 by mbouthai          #+#    #+#             */
/*   Updated: 2022/01/22 21:26:31 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*first;
	unsigned char	*second;

	if (!n)
		return (0);
	index = 0;
	first = (unsigned char *)s1;
	second = (unsigned char *)s2;
	while (index < n)
	{
		if (first[index] != second[index])
			return (first[index] - second[index]);
		index++;
	}
	return (0);
}
