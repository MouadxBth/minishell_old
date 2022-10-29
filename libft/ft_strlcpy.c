/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:46:28 by mbouthai          #+#    #+#             */
/*   Updated: 2022/01/26 00:40:51 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	if (size > 0)
	{
		index = -1;
		while (src[++index] && index < (size - 1))
			dst[index] = src[index];
		dst[index] = '\0';
	}
	return (ft_strlen(src));
}
