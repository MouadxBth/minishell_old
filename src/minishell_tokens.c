/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:22:52 by mbouthai          #+#    #+#             */
/*   Updated: 2023/01/09 13:10:04 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*token_names[] = {
	"NONE",		// 0
	"CMDSTART",	// 1
	"CMDEND",		// 2
	"WSPACE",		// 3
	"AND",		// 4
	"OR",		// 5
	"WORD",		// 6
	"SINGLE_QUOTES",	// 7
	"DOUBLE_QUOTES",	// 8
	"OPEN_PAR",	// 9
	"CLOSE_PAR",	// 10
	"DOLLAR",		// 11
	"IN_REDIRECT",	// 12
	"OUT_REDIRECT",	// 13
	"IN_APPEND",	// 14
	"OUT_APPEND",	// 15
	"PIPE",		// 16
	"TILDE"		// 17
};

t_token	*ft_new_token(t_token_type type, char *value)
{
	t_token	*result;

/*	if (!value)
		return (NULL);*/
	result = (t_token *)malloc(sizeof(t_token));
	if (!result)
		return (NULL);
	result->type = type;
	result->value = value;
	return (result);
}

void	ft_free_token(void *arg)
{
	t_token	*token;

	token = (t_token *)arg;
	if (!token)
		return ;
	if (token->value)
		free(token->value);
	free(token);
}


void	ft_print_tokens(t_list	*head)
{
	t_token	*token;

	if (!head)
	{
		ft_putstr_fd("Invalid Command!\n", 2);
		return ;
	}
	while (head)
	{
		token = (t_token *)head->content;
		printf("Token { type: %20s value: %20s }\n", token_names[token->type], token->value);
		head = head->next;
	}
}

int	ft_count_token(t_list *list, t_token_type *types)
{
	int	result;
	int	index;
	t_token	*token;

	if (!list)
		return (0);
	result = 0;
	token = (t_token *)list->content;
	while (list)
	{
		index = -1;
		while (types[++index])
		{
			if (token->type == types[index])
				result++;
		}
		list = list->next;
		if (list)
			token = (t_token *)list->content;
	}
	return (result);
}
