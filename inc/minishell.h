/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 03:26:02 by mbouthai          #+#    #+#             */
/*   Updated: 2022/12/24 14:27:07 by mbouthai         ###   ########.fr       */
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

typedef int (*t_predicate)(int);

typedef enum	e_token_type
{
	CMDSTART,
	CMDEND,
	AND,
	OR,
	WORD,
	SINGLE_QUOTES,
	DOUBLE_QUOTES,
	OPEN_PAR,
	CLOSE_PAR,
	DOLLAR,
	IN_REDIRECT,
	OUT_REDIRECT,
	IN_APPEND,
	OUT_APPEND,
	PIPE,
	TILDE,
	NONE
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

int	ft_validate(char *str);

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

/* PREDICATES */
int	ft_is_space(int c);
int	ft_sq(int c);
int	ft_dq(int c);
int	ft_custom(int c);

#endif
