/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process_io.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:56:36 by fernando          #+#    #+#             */
/*   Updated: 2025/02/01 18:23:31 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	close_pipes(t_command *command, t_pipe **pipeline, int t)
{
	int	i;

	i = 0;
	if (command->here[1] != -1)
		close(command->here[1]);
	while ((i < (t - 1)))
	{
		close_t_pipe((*pipeline)[i]);
		i++;
	}
}

int	set_process_io(t_command *command, t_pipe **pipeline, int t)
{
	if ((command->input == -1) || (command->output == -1))
	{
		close_pipes(command, pipeline, t);
		free(*pipeline);
		return (0);
	}
	if (command->output != STDOUT_FILENO)
	{
		dup2(command->output, STDOUT_FILENO);
		close(command->output);
	}
	else if (command->not_last == 1)
		dup2((*pipeline)[command->run][1], STDOUT_FILENO);
	if (command->input != STDIN_FILENO)
	{
		dup2(command->input, STDIN_FILENO);
		close(command->input);
	}
	else if (command->run != 0)
		dup2((*pipeline)[command->run - 1][0], STDIN_FILENO);
	close_pipes(command, pipeline, t);
	free(*pipeline);
	return (1);
}

void	close_t_pipe(t_pipe pipe)
{
	if (pipe[1] != -1)
		close(pipe[1]);
	if (pipe[0] != -1)
		close(pipe[0]);
}
