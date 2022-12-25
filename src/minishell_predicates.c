/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_predicates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:03:59 by mbouthai          #+#    #+#             */
/*   Updated: 2022/12/19 22:07:31 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_space(int c)
{
	return (c == ' ' || (c >= 9 && c <= 19));
}

int	ft_sq(int c)
{
	return (c == '\'');
}

int	ft_dq(int c)
{
	return (c == '\"');
}

int	ft_custom(int c)
{
	return (ft_is_space(c) || ft_sq(c) || ft_dq(c));
}
