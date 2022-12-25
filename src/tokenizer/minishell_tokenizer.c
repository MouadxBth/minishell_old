/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tokenizer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:40:38 by mbouthai          #+#    #+#             */
/*   Updated: 2022/12/24 13:11:10 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * echo -n "$PATH" '((5+7)*9)'
 *
 * */

static char	*ft_whitespaces(char *str)
{
	if (!str)
		return (NULL);
	while (*str && ft_is_space(*str))
		str++;
	return (str);
}

static t_token	*ft_sq(char **str)
{
	int	length;
	t_token	*result;

	if (!str || !result)
		return (NULL);
	length = 0;
	while (*str[length] && *str[length] != '\'' &&
		*str[length] != '\n')
		length++;
	result = ft_new_token(SINGLE_QUOTES, ft_substr(*str, 0, length + 1));
	if (*str[length] == '\'')
		length++;
	*str = *str + length;
	return (result);
}

static t_token	*ft_dq(char **str)
{
	int	length;
	t_token	*result;
}

t_list	*ft_tokenize(char *str)
{
	t_list	*result;

	if (!str)
		return (NULL);
	while (*str && *str != '\n')
	{
		if (ft_is_space(*str))
			str = ft_whitespaces(str);
		else if (str[index] == '\'')
			str = ft_sq(++str, result);
	}
	return (NULL);
}
