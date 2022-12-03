/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tokenizer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:47:12 by mbouthai          #+#    #+#             */
/*   Updated: 2022/11/07 00:51:03 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static t_token	*ft_get_token(char *str)
{
	t_token	*result;

	if (!str)
		return (NULL);
	if (str[0] == '\"')
		result = ft_new_token(DOUBLE_QUOTES, ft_strtrim(str, "\""));
	else if (str[0] == '\'')
		result = ft_new_token(SINGLE_QUOTES, ft_strtrim(str, "\'"));
	else
		result = ft_new_token(WORD, ft_strdup(str));
	return (result);
}

static char	*ft_skip_spaces(char *str)
{
	if (!str)
		return (NULL);
	while (ft_is_space(*str))
		str++;
	return (str);
}

static t_token	*ft_token(char **str, char c)
{
	if (!str || !c)
		
}

t_list	*ft_tokenize(char *str)
{
	t_list	*result;
	
	if (!str)
		return (NULL);
	while (*str)
	{
		str = ft_skip_spaces(str);
		if (*str == '\'')
		{

		}
		else if (*str == '\"')
		{
		}
		else
		{
		}
	}
}

t_list	*ft_tokenize(char *str)
{
	t_list	*result;
	t_token	*token;
	int	length;

	if (!str)
		return (NULL);
	while (*str)
	{
		str = ft_skip_spaces(str);
		if (str[index] == '\"')
		{
			length = 0;
			while (str[index + length]
				&& str[index + length] != '\n'
				&& str[index + length] != '\"')
				length++;

		}
		else if (str[index] == '\'')
		{
		}
		else
		{
		}
	}
	while (words[index])
	{
		token = ft_get_token(words[index]);
		if (!result)
			result = ft_lstnew(token);
		else
			ft_lstadd_back(&result, ft_lstnew(token));
		index++;
	}
	index = 0;
	while (words[index])
		free(words[index++]);
	free(words);
	return (result);
}

/*t_list	*ft_tokenize(char *str)
{
	t_list	*result;
	t_token	*token;
	int	index;
	char	**words;

	if (!str)
		return (NULL);
	index = 0;
	words = ft_fsplit(str, ft_is_space);
	result = NULL;
	while (words[index])
	{
		token = ft_get_token(words[index]);
		if (!result)
			result = ft_lstnew(token);
		else
			ft_lstadd_back(&result, ft_lstnew(token));
		index++;
	}
	index = 0;
	while (words[index])
		free(words[index++]);
	free(words);
	return (result);
}*/
