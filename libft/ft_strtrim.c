/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:33:28 by mbouthai          #+#    #+#             */
/*   Updated: 2022/02/20 14:19:31 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_contains(int c, char const *str)
{
	while (*str && (unsigned char)c != *str)
		str++;
	return ((unsigned char)c == *str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_str_contains(s1[start], set))
		start++;
	while (end > start && ft_str_contains(s1[end - 1], set))
		end--;
	result = (char *)malloc(sizeof(char) * (end - start + 1));
	if (result != NULL)
		ft_strlcpy(result, s1 + start, end - start + 1);
	return (result);
}
