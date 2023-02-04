/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_syntax_analyser.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:45:00 by mbouthai          #+#    #+#             */
/*   Updated: 2023/01/09 13:15:38 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
static int	ft_sq(t_list *list)
{
	t_token	*token;

	if (!list)
		return (0);
	token = (t_token *)list->content;
	while (list)
	{
		if (token->type == SINGLE_QUOTES)
			return (1);
		list = list->next;
		if (list)
			token = (t_token *)list->content;
	}
	return (0);
}*/

int	ft_analyze(t_list *list)
{
	//t_token	*token;
	t_token_type types[] = {SINGLE_QUOTES, DOUBLE_QUOTES};
	int	t;

	if (!list)
		return (0);
	t = ft_count_token(list, types);
	printf("%i\n", t);
	if (t % 2 != 0)
		return (0);
	/*/
	token = (t_token *)list->content;
	while (list)
	{
		if (token->type == SINGLE_QUOTES && !ft_sq(list->next))
			return (0);
		list = list->next;
		if (list)
			token = (t_token *)list->content;
	}*/
	return (1);
}
