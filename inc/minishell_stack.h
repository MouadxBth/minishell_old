/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_stack.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:12:08 by mbouthai          #+#    #+#             */
/*   Updated: 2022/12/29 20:12:45 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STACK_H
# define MINISHELL_STACK_H

typedef struct	s_element
{
	int	value;
	struct s_element	*next;
}	t_element;

typedef t_element	*t_stack;

int	ft_push(t_stack *stack, int value);

int		ft_pop(t_stack *stack);

int		ft_fill(t_stack *stack, int argc, char **argv);

int		ft_stack_size(t_stack *stack);

void	ft_free(t_stack *stack);

t_element	*ft_fetch(t_stack *stack, int value);

#endif
