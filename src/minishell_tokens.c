/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:22:52 by mbouthai          #+#    #+#             */
/*   Updated: 2022/10/30 16:34:34 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_new_token(t_token_type type, char *value)
{
	t_token	*result;

	if (!value)
		return (NULL);
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
	free(token->value);
	free(token);
}


void	ft_print_tokens(t_list	*head)
{
	t_token	*token;

	if (!head)
		return ;
	while (head)
	{
		token = (t_token *)head->content;
		printf("Token { type: %d value: %s }\n", token->type, token->value);
		head = head->next;
	}
}
