/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:40:38 by mbouthai          #+#    #+#             */
/*   Updated: 2023/01/09 00:36:19 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_whitespaces(char *str, t_list **list)
{
	int	length;
	t_token	*token;

	if (!str)
		return (NULL);
	length = 0;
	while (str[length] && ft_is_space(str[length]))
		length++;
	if (length)
	{
		token = ft_new_token(WSPACE, NULL);
		ft_lstadd(list, ft_lstnew(token), 0);
	}
	return (str + length);
}

static char	*ft_word(char *str, t_list **list)
{
	int	length;
	t_token	*token;

	if (!str)
		return (NULL);
	length = 0;
	while (!ft_strchr("\'\"()$<>|", str[length]) && !ft_is_space(str[length]))
		length++;
	if (length)
	{
		token = ft_new_token(WORD, ft_substr(str, 0, length));
		ft_lstadd(list, ft_lstnew(token), 0);
	}
	return (str + length);
}

static t_token_type	ft_redirect(char **str)
{
	t_token_type	type;
	int	length = 0;
	
	type = NONE;
	if (*str[0] == '>')
	{
		length = 1;
		if (str[0][1] == '>')
		{
			length = 2;
			type = IN_APPEND;
		}
		else
			type = IN_REDIRECT;
	}
	else if (*str[0] == '<')
	{
		length = 1;
		if (str[0][1] == '<')
		{
			length = 2;
			type = OUT_APPEND;
		}
		else
			type = OUT_REDIRECT;
	}
	*str += length;
	return (type);
}

static char	*ft_simple_token(char *str, t_list **list)
{
	t_token	*token;
	t_token_type	type;

	if (!str)
		return (NULL);
	type = (*str == '(') * OPEN_PAR 
		+ (*str == ')') * CLOSE_PAR
		+ (*str == '\'') * SINGLE_QUOTES
		+ (*str == '\"') * DOUBLE_QUOTES
		+ (*str == '$') * DOLLAR
		+ (*str == '|') * PIPE
		+ (*str == '~') * TILDE;
	if (!type)
	{
		type = ft_redirect(&str);
		if (!type)
			return (str);
	}
	token = ft_new_token(type, NULL);
	return (ft_lstadd(list, ft_lstnew(token), 0), str + 1);
}

t_list	*ft_tokenize(char *str)
{
	t_list	*result;

	if (!str)
		return (NULL);
	result = NULL;
	ft_lstadd(&result, ft_lstnew(ft_new_token(CMDSTART, NULL)), 0);
	while (*str && *str != '\n')
	{
		str = ft_whitespaces(str, &result);
		str = ft_word(str, &result);
		str = ft_simple_token(str, &result);
	}
	ft_lstadd(&result, ft_lstnew(ft_new_token(CMDEND, NULL)), 0);
	return (result);
}
