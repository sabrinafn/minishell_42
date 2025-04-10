/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:35:44 by fernando          #+#    #+#             */
/*   Updated: 2025/01/28 18:36:02 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	update_env_vars(void)
{
	char	*old_pwd;
	char	*temp;
	char	*pwd;

	temp = getcwd(NULL, 0);
	if (!temp)
		return ;
	old_pwd = ft_strjoin("OLDPWD=", temp);
	add_env_var(old_pwd);
	pwd = ft_strjoin("PWD=", temp);
	add_env_var(pwd);
	free(temp);
	free(pwd);
	free(old_pwd);
}

void	ft_cd_run(char **argv)
{
	if (argv[2] != NULL)
	{
		write_stderr(" too many arguments", 1);
		*current_exit_code() = 1;
		return ;
	}
	if (chdir(argv[1]) == 0)
	{
		update_env_vars();
		*current_exit_code() = 0;
	}
	else
	{
		write_stderr(" No such file or directory", 1);
		*current_exit_code() = 1;
	}
}

void	ft_cd(char **argv)
{
	(void)argv;
}
