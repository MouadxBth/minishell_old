/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:06:54 by mbouthai          #+#    #+#             */
/*   Updated: 2022/12/24 01:31:57 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 0  */
/* t_element * -> t_stack */

int	ft_push(t_stack *stack, int value)
{
	t_element	*new_element;

	new_element = (t_element *)malloc(sizeof(t_element));
	if (!new_element)
		return (0);
	new_element->value = value;
	if (!stack)
	{
		new_element->next = NULL;
		stack = &new_element;
	}
	else
	{
		new_element->next = *stack;
		*stack = new_element;
	}
	return (1);
}

int	ft_pop(t_stack *stack)
{
	int		result;
	t_element	*temp;

	if (!stack)
		return (-1);
	if (!*stack)
		return (-1);
	result = (*stack)->value;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
	return (result);
}

void	ft_free(t_stack *stack)
{
	t_element	*index;
	t_element	*temp;

	if (!stack)
		return ;
	if (!*stack)
		return ;
	index = *stack;
	while (index)
	{
		temp = index;
		index = index->next;
		free(temp);
	}
}

t_element	*ft_fetch(t_stack *stack, int value)
{
	t_element	*index;

	if (!stack || !*stack)
		return (NULL);
	index = *stack;
	while (index)
	{
		if (index->value == value)
			return (index);
		index = index->next;
	}
	return (NULL);
}

int	ft_stack_size(t_stack *stack)
{
	t_element	*index;
	int		size;

	if (!stack || !*stack)
		return (0);
	index = *stack;
	size = 0;
	while (index)
	{
		index = index->next;
		size++;
	}
	return (size);
}
