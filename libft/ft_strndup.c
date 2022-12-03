/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 22:51:50 by mbouthai          #+#    #+#             */
/*   Updated: 2022/11/03 15:26:36 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str, int start, size_t length)
{
	char	*result;
	size_t	str_length;

	if (!str)
		return (NULL);
	str_length = ft_strlen(str);
	result = (char *)malloc(sizeof(char) * str_length + 1);
	if (result != NULL)
		ft_strlcpy(result, str, str_length + 1);
	return (result);
}	
