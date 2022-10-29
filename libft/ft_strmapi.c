/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:22:27 by mbouthai          #+#    #+#             */
/*   Updated: 2022/02/20 14:22:12 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	size_t	length;
	char	*result;

	if (!s)
		return (NULL);
	index = 0;
	length = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (result != NULL)
	{
		while (index < length)
		{
			result[index] = f(index, s[index]);
			index++;
		}
		result[index] = '\0';
	}
	return (result);
}
