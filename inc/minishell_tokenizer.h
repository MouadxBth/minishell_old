/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tokenizer.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:07:51 by mbouthai          #+#    #+#             */
/*   Updated: 2023/01/09 13:38:26 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHEL_TOKENIZER_H
# define MINISHEL_TOKENIZER_H

typedef int (*t_predicate)(int);

typedef enum	e_token_type
{
	NONE,		// 0
	CMDSTART,	// 1
	CMDEND,		// 2
	WSPACE,		// 3
	AND,		// 4
	OR,		// 5
	WORD,		// 6
	SINGLE_QUOTES,	// 7
	DOUBLE_QUOTES,	// 8
	OPEN_PAR,	// 9
	CLOSE_PAR,	// 10
	DOLLAR,		// 11
	IN_REDIRECT,	// 12
	OUT_REDIRECT,	// 13
	IN_APPEND,	// 14
	OUT_APPEND,	// 15
	PIPE,		// 16
	TILDE		// 17
}	t_token_type;


typedef struct	s_token
{
	t_token_type	type;
	char		*value;
}	t_token;

t_token	*ft_new_token(t_token_type type, char *value);
void	ft_free_token(void *arg);
void	ft_print_tokens(t_list *head);
int	ft_count_token(t_list *list, t_token_type *type);

int	ft_is_space(int c);

t_list	*ft_tokenize(char *str);

int	ft_analyze(t_list *tokens);

#endif
