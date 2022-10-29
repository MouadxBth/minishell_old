/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 04:30:09 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/21 11:23:22 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_interrupt_handler(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
}

void	ft_block_signals()
{
	if (signal(SIGINT, ft_interrupt_handler) == SIG_ERR
		|| signal(SIGQUIT, SIG_IGN) == SIG_ERR
		|| signal(SIGTSTP, SIG_IGN) == SIG_ERR)
		exit(1);
}

void	ft_unblock_signals()
{
	if (signal(SIGINT, SIG_DFL) == SIG_ERR
		|| signal(SIGQUIT, SIG_DFL) == SIG_ERR
		|| signal(SIGTSTP, SIG_DFL) == SIG_ERR)
		exit(1);
}
