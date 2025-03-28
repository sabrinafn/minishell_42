/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   script_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:11:47 by fernando          #+#    #+#             */
/*   Updated: 2025/01/29 02:27:45 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	script_files(char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd != -1)
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	else
	{
		write_stderr("Error opening file: ", 0);
		write_stderr(av[1], 1);
		exit(1);
	}
}
