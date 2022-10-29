/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 03:26:20 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/16 05:20:32 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_list	*envs;
	char	*cmd;

	(void) argc;
	(void) argv;
	(void) env;
	ft_block_signals();
	ft_configure_termios();
	envs = NULL;
	while (1)
	{
		cmd = readline("minishell$ ");
		if (!cmd)
			break ;
		if (!envs)
			envs = ft_lstnew(ft_new_env(cmd, cmd));
		else
			ft_lstadd_front(&envs, ft_lstnew(ft_new_env(cmd, cmd)));
		ft_print_envs(envs);
		add_history(cmd);
		printf("COMMAND: %s\n", cmd);
		free(cmd);
	}
	ft_lstclear(&envs, ft_free_env);
	ft_unblock_signals();
	ft_restore_termios();
	return (0);
}
