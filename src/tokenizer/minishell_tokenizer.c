/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tokenizer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:40:38 by mbouthai          #+#    #+#             */
/*   Updated: 2023/01/08 23:27:21 by mbouthai         ###   ########.fr       */
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
		token = ft_new_token(WSPACE, ft_strdup(" "));
		ft_lstadd(list, ft_lstnew(token), 0);
	}
	return (str + length);
}


static char	*ft_sq(char *str, t_list **list)
{
	t_token	*token;

	if (!str)
		return (NULL);
	if (*str == '\'')
	{
		token = ft_new_token(SINGLE_QUOTES, ft_strdup("'"));
		return (ft_lstadd(list, ft_lstnew(token), 0), str++);
	}
	return (str);
}

static char	*ft_dq(char *str, t_list **list)
{
	t_token	*token;

	if (!str)
		return (NULL);
	if (*str == '\"')
	{
		token = ft_new_token(DOUBLE_QUOTES, ft_strdup("\""));
		return (ft_lstadd(list, ft_lstnew(token), 0), str++);
	}
	return (str);
}

static char	*ft_word(char *str, t_list **list)
{
	int	length;
	t_token	*token;

	if (!str)
		return (NULL);
	length = 0;
	while (!ft_strchr("\'\"()$<>&|;", str[length]) && !ft_is_space(str[length]))
		length++;
	if (length)
	{
		token = ft_new_token(WORD, ft_substr(str, 0, length));
		ft_lstadd(list, ft_lstnew(token), 0);
	}
	return (str + length);
}

t_list	*ft_tokenize(char *str)
{
	t_list	*result;

	if (!str)
		return (NULL);
	result = NULL;
	while (*str && *str != '\n')
	{
		str = ft_whitespaces(str, &result);
		str = ft_simple_token(str, &result);
		str = ft_word(str, &result);
	/*	str = ft_sq(str, &result);
		str = ft_dq(str, &result);*/
	}
	return (result);
}
