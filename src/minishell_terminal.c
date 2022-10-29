/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_terminal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 04:15:04 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/16 04:38:23 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_configure_termios()
{
	struct termios	terminal;

	if (tcgetattr(STDIN_FILENO, &terminal) < 0)
		exit(1);
	terminal.c_lflag &= ~(ECHOCTL);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &terminal) < 0)
		exit(1);
}

void	ft_restore_termios()
{
	struct termios	terminal;

	if (tcgetattr(STDIN_FILENO, &terminal) < 0)
		exit(1);
	terminal.c_lflag |= ECHOCTL;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &terminal) < 0)
		exit(1);
}
