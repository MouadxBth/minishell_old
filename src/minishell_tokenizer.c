/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tokenizer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:36:05 by mbouthai          #+#    #+#             */
/*   Updated: 2022/12/24 02:06:09 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*ft_token(char **s, t_token_type t, t_predicate p)
{
	int		length;
	char	*str;
	t_token	*result;

	if (!s || !*s)
		return (NULL);
	str = *s;
	if (t != WORD)
		str++;
	length = 0;
	while (str[length] && !p(str[length]))
		length++;
	result = ft_new_token(t, ft_substr(str, 0, length));
	if (t != WORD)
		length++;
	*s = str + length;
	return (result);
}

static t_token_type	ft_token_type(int c)
{
	if (c == '\"')
		return (DOUBLE_QUOTES);
	else if (c == '\'')
		return (SINGLE_QUOTES);
	else if (c != '\0')
		return (WORD);
	return (NONE);
}

static t_predicate	ft_predicate(t_token_type type)
{
	if (type == DOUBLE_QUOTES)
		return (ft_dq);
	else if (type == SINGLE_QUOTES)
		return (ft_sq);
	else if (type == WORD)
		return (ft_custom);
	else
		return (NULL);
}

static char	*ft_skip_spaces(char *str)
{
	if (!str)
		return (NULL);
	while (*str && ft_is_space(*str))
		str++;
	return (str);
}

t_list	*ft_tokenize(char *str)
{
	t_list			*result;
	t_token			*token;
	t_predicate		predicate;
	t_token_type	type;

	if (!str)
		return (NULL);
	if (!ft_validate(str))
		return (NULL);
	result = NULL;
	while (*str)
	{
		str = ft_skip_spaces(str);
		type = ft_token_type(*str);
		predicate = ft_predicate(type);
		if (type == NONE || !predicate)
			break ;
		token = ft_token(&str, type, predicate);
		if (!result)
			result = ft_lstnew(token);
		else
			ft_lstadd_back(&result, ft_lstnew(token));
	}
	return (result);
}
