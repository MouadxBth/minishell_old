/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:34:47 by mbouthai          #+#    #+#             */
/*   Updated: 2022/02/20 14:05:34 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memmove_left(unsigned char *dst, unsigned char *src, int n)
{
	int	index;

	index = -1;
	while (++index < n)
		dst[index] = src[index];
	return (dst);
}

static void	*ft_memmove_right(unsigned char *dst, unsigned char *src, int n)
{
	while (--n >= 0)
		dst[n] = src[n];
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*from;
	unsigned char	*to;

	if (!dst && !src)
		return (NULL);
	from = (unsigned char *)src;
	to = (unsigned char *)dst;
	if (from > to && (size_t)(from - to) < n)
		return (ft_memmove_left(to, from, n));
	if (to > from && (size_t)(to - from) < n)
		return (ft_memmove_right(to, from, n));
	return (ft_memcpy(dst, src, n));
}
