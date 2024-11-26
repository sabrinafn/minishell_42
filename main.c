/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 01:05:51 by sabrifer          #+#    #+#             */
/*   Updated: 2024/11/08 01:06:38 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	char		*line;
	char		*prompt;
	t_envp_lst	*env_vars;

	(void)ac;
	(void)av;
	line = NULL;
	env_vars = store_envp(envp);
	*env_vars_list() = env_vars;
	handle_signals();
	while (1)
	{
		prompt = get_prompt();
		line = readline(prompt);
		if (line == NULL)
		{
			// this break handles ctrl + d (sigquit) this here needs to be fixed still
			break ;
		}
		add_history(line);
		clear_args_list(args_list());
		*args_list() = ft_lst_split(line);
		ft_lexer(args_list());
		handle_environment_vars_expansion(args_list());
		run_commands();
		free_args_lst(args_list());
	}
	free_env_lst(env_vars_list());
	free_all();
	rl_clear_history();
	return (0);
}
