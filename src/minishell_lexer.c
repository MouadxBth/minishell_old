/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_lexer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:04:27 by mbouthai          #+#    #+#             */
/*   Updated: 2022/10/29 20:22:34 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_count_tokens(char *str)
{
	int	index;
	int	result;

	if (!str)
		return (0);
	index = -1;
	result = 0;
	while (str[++index])
	{
		if (str[index] == ' ')
			result++;
	}
	return (result);
}

t_token	*ft_tokenize(char *str)
{
	int	index;
	t_token	*result;
	
	if (!str)
		return (0);


}
