/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 22:51:50 by mbouthai          #+#    #+#             */
/*   Updated: 2022/01/22 23:00:42 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*result;
	size_t	str_length;

	str_length = ft_strlen(str);
	result = (char *)malloc(sizeof(char) * str_length + 1);
	if (result != NULL)
		ft_strlcpy(result, str, str_length + 1);
	return (result);
}	
