/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:43:46 by mbouthai          #+#    #+#             */
/*   Updated: 2022/01/26 01:55:58 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	index;
	int	c_index;

	index = -1;
	c_index = -1;
	while (s[++index])
		if ((unsigned char)c == s[index])
			c_index = index;
	if (s[index] == (unsigned char)c)
		return ((char *)s + index);
	if (c_index >= 0)
		return ((char *)s + c_index);
	return (NULL);
}
