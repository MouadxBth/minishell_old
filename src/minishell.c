/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 03:26:20 by mbouthai          #+#    #+#             */
/*   Updated: 2022/11/03 11:18:07 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_list	*tokens;
	int	exit;
	char	*cmd;

	(void) argc;
	(void) argv;
	(void) env;
	ft_block_signals();
	ft_configure_termios();
	tokens = NULL;
	exit = 0;
	while (!exit)
	{
		cmd = readline("minishell$ ");
		if (!cmd)
			break ;
		if (cmd[0] == '0')
			exit = 1;
		tokens = ft_tokenize(cmd);
		ft_print_tokens(tokens);
		ft_lstclear(&tokens, ft_free_token);

		add_history(cmd);
		free(cmd);
	}
	ft_unblock_signals();
	ft_restore_termios();
	return (0);
}
