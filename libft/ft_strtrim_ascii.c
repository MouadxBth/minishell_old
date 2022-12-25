/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_ascii.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:33:28 by mbouthai          #+#    #+#             */
/*   Updated: 2022/12/16 19:07:32 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int ft_is_in_range(int c, int start, int end)
{
	return (c >= start && c <= end);
}

char	*ft_strtrim_ascii(char const *s1, int start_ascii, int end_ascii)
{
	char	*result;
	size_t	start;
	size_t	end;

	if (!s1 || start_ascii < 0 || end_ascii < 0)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_is_in_range(s1[start], start_ascii, end_ascii))
		start++;
	while (end > start && ft_is_in_range(s1[end - 1], start_ascii, end_ascii))
		end--;
	result = (char *)malloc(sizeof(char) * (end - start + 1));
	if (result != NULL)
	{
		printf("Copying\n");
		ft_strlcpy(result, s1 + start, end - start + 1);
	}
	return (result);
}
