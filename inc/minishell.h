/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 03:26:02 by mbouthai          #+#    #+#             */
/*   Updated: 2022/11/09 13:37:50 by mbouthai         ###   ########.fr       */
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

# define RESET "\001\033[0m\002"
# define GREEN "\001\033[1;32m\002"
# define RED "\033[0;31m"
/*
 *

# define RED: \u001b[31m
# define GREEN \u001b[32m
# define YELLOW \u001b[33m
# define BLUE \u001b[34m
# define MAGENTA \u001b[35m
# define CYAN \u001b[36m
# define RESET \u001b[0m
 * */
typedef enum	e_token_type
{
	WORD,
	SINGLE_QUOTES,
	DOUBLE_QUOTES
}	t_token_type;

typedef struct	s_token
{
	t_token_type	type;
	char		*value;
}	t_token;

typedef struct	s_env
{
	char	*key;
	char	*value;
}	t_env;

typedef struct	s_node
{
	void	*content;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

int	ft_error(char *str, int code);

void	ft_block_signals();
void	ft_unblock_signals();

void	ft_configure_termios();
void	ft_restore_termios();

t_env	*ft_new_env(char *key, char *value);
void	ft_print_envs(t_list *envs);
void	ft_free_env(void *env);

t_token	*ft_new_token(t_token_type type, char *value);
void	ft_free_token(void *arg);
void	ft_print_tokens(t_list *head);

t_list	*ft_tokenize(char *str);

#endif
