/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_validator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:02:17 by mbouthai          #+#    #+#             */
/*   Updated: 2022/12/24 02:01:58 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_occurrence(char *str, int c)
{
	int	index;
	int	result;

	index = -1;
	result = 0;
	while (str[++index])
		if (str[index] == c)
			result++;
	return (result);
}

int	ft_validate(char *str)
{
	int	index;
	int	result;
	t_stack	stack;

	if (!str)
		return (0);
	if (ft_occurrence(str, '\'') % 2 != 0
		|| ft_occurrence(str, '\"') % 2 != 0)
		return (0);
	index = -1;
	stack = NULL;
	while (str[++index])
	{
		if (str[index] == '(')
			ft_push(&stack, str[index]);
	}
	index = ft_strlen(str) - 1;
	while (str[index])
	{
		if (str[index--] == ')' && stack->value == '(')
			ft_pop(&stack);
	}
	result = ft_stack_size(&stack);
	ft_free(&stack);
	return (!result);
}
