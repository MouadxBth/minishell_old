/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:43:20 by mbouthai          #+#    #+#             */
/*   Updated: 2022/02/20 14:10:05 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_length;
	size_t	src_length;
	size_t	index;

	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (size <= dst_length)
		return (size + src_length);
	index = -1;
	while (src[++index] && index < (size - dst_length - 1))
		dst[dst_length + index] = src[index];
	dst[dst_length + index] = '\0';
	return (dst_length + src_length);
}
