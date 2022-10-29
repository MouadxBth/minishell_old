/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 04:55:51 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/16 05:08:01 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_new_env(char *key, char *value)
{
	t_env	*result;

	result = (t_env *)malloc(sizeof(t_env));
	if (!result)
		return (NULL);
	result->key = ft_strdup(key);
	result->value = ft_strdup(value);
	return (result);
}

void	ft_free_env(void *arg)
{
	t_env	*env;

	env = (t_env *)arg;
	if (!env)
		return ;
	if (env->key)
		free(env->key);
	if (env->value)
		free(env->value);
	free(env);
}

void	ft_print_envs(t_list *head)
{
	t_env	*env;

	while (head)
	{
		env = (t_env *)head->content;
		printf("KEY: %s VALUE: %s\n", env->key, env->value);
		head = head->next;
	}
}
