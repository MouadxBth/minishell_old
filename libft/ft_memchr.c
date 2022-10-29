/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:31:07 by mbouthai          #+#    #+#             */
/*   Updated: 2022/01/22 21:36:22 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*memory;

	index = 0;
	memory = (unsigned char *)s;
	while (index < n)
	{
		if (memory[index] == (unsigned char)c)
			return ((void *)(s + index));
		index++;
	}
	return (NULL);
}
