/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_env.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:13:33 by mbouthai          #+#    #+#             */
/*   Updated: 2022/12/29 20:14:02 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_ENV_H
# define MINISHELL_ENV_H

typedef struct	s_env
{
	char	*key;
	char	*value;
}	t_env;

t_env	*ft_new_env(char *key, char *value);

void	ft_print_envs(t_list *envs);

void	ft_free_env(void *env);

#endif
