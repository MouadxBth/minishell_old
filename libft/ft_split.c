/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:54:39 by mbouthai          #+#    #+#             */
/*   Updated: 2022/02/20 14:17:40 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	ft_skip_delim(const char *str, size_t *index, int delim)
{
	while (str[*index] && str[*index] == delim)
		*index = *index + 1;
}

static size_t	ft_wordcount(const char *str, int delim)
{
	size_t	count;
	int		is_word;

	count = 0;
	is_word = 0;
	while (*str)
	{
		if (*str == delim)
			is_word = 0;
		else if (!is_word)
		{
			is_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static size_t	ft_wordlen(const char *str, size_t start, int delim)
{
	size_t	length;

	length = 0;
	while (str[start + length] && str[start + length] != delim)
		length++;
	return (length);
}

static size_t	ft_wordcpy(char **dst, const char *src, size_t start, int c)
{
	size_t	length;

	length = ft_wordlen(src, start, c);
	if (length)
	{
		*dst = (char *)malloc(sizeof(char) * (length + 1));
		if (*dst != NULL)
			ft_strlcpy(*dst, src + start, length + 1);
	}
	return (length);
}

char	**ft_split(const char *str, char c)
{
	size_t	words;
	size_t	index;
	size_t	current;
	char	**result;

	if (!str)
		return (NULL);
	words = ft_wordcount(str, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (result != NULL)
	{
		index = 0;
		current = 0;
		while (index < words)
		{
			ft_skip_delim(str, &current, c);
			current += ft_wordcpy(&result[index], str, current, c);
			index++;
		}
		result[index] = NULL;
	}
	return (result);
}
