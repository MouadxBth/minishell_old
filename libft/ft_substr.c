/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 23:02:00 by mbouthai          #+#    #+#             */
/*   Updated: 2022/02/20 14:16:03 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*result;
	size_t	str_len;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (start > str_len)
		start = str_len;
	if (len > str_len - start)
		len = str_len - start;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result != NULL)
		ft_strlcpy(result, str + start, len + 1);
	return (result);
}
