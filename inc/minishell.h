/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 03:26:02 by mbouthai          #+#    #+#             */
/*   Updated: 2022/12/29 20:22:07 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <unistd.h>
# include <dirent.h>
# include <fcntl.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include "libft.h"

# include "minishell_tokenizer.h"
# include "minishell_colors.h"
# include "minishell_env.h"
# include "minishell_stack.h"

typedef struct	s_node
{
	void	*content;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

int	ft_validate(char *str);

int	ft_error(char *str, int code);

void	ft_block_signals();
void	ft_unblock_signals();

void	ft_configure_termios();
void	ft_restore_termios();

#endif
