/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tokenizers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:42:30 by mbouthai          #+#    #+#             */
/*   Updated: 2022/11/09 18:39:55 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_is_space(int c)
{
	return (c == ' ' || (c >= 9 && c <= 19));
}

static int	ft_sq(int c)
{
	return (c == '\'');
}

static int	ft_dq(int c)
{
	return (c == '\"');
}

static char	*ft_skip_spaces(char *str)
{
	if (!str)
		return (NULL);
	while (*str && ft_is_space(*str))
		str++;
	return (str);
}

static int	ft_custom(int c)
{
	return (ft_is_space(c) || c == '\'' || c == '\"');
}

static t_token	*ft_token(char **str_add, t_token_type type, int (*predicate)(int))
{
	char	*str;
	t_token	*result;
	int	length;

	if (!str_add || !*str_add)
		return (NULL);
	str = *str_add;
	length = 0;
	while (str[length] && !predicate(str[length]))
		length++;
	result = ft_new_token(type, ft_substr(str, 0, length));
	*str_add = str + length;
	return (result);
}
/*
static t_token	*ft_sq_token(char **str_add)
{
	char	*str;
	t_token	*result;
	int	length;

	if (!str_add || !*str_add)
		return (NULL);
	str = *str_add;
	length = 0;
	while (str[length] && str[length] != '\'')
		length++;
	result = ft_new_token(SINGLE_QUOTES, ft_substr(str, 0, length));
	*str_add = str + 1 + length;
	return (result);
}*/

t_list	*ft_tokenize(char *str)
{
	t_list	*result;
	t_token	*token;

	if (!str)
		return (NULL);
	result = NULL;
	while (*str)
	{
		str = ft_skip_spaces(str);
		if (*str == '\"')
		{
			str++;
			token = ft_token(&str, DOUBLE_QUOTES, ft_dq);
			if (!result)
				result = ft_lstnew(token);
			else
				ft_lstadd_back(&result, ft_lstnew(token));
			str++;
		}
		else if (*str == '\'')
		{
			str++;
			token = ft_token(&str, SINGLE_QUOTES, ft_sq);
			if (!result)
				result = ft_lstnew(token);
			else
				ft_lstadd_back(&result, ft_lstnew(token));
			str++;
		}
		else if (*str != '\0')
		{
			token = ft_token(&str, WORD, ft_custom);
			if (!result)
				result = ft_lstnew(token);
			else
				ft_lstadd_back(&result, ft_lstnew(token));
		}
	}
	return (result);
}
