/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:48:51 by fernando          #+#    #+#             */
/*   Updated: 2025/02/01 19:56:40 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUILT_INS 7

# include <fcntl.h>
# include <termios.h>
# include <stdbool.h>
# include <stdio.h>
# include "./libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>
# include <signal.h>
# include <errno.h>
# include "minishell_typedefs.h"
# include "signals/handle_signals.h"
# include "utils/utils.h"
# include "statics/statics.h"
# include "run_commands/run_commands.h"
# include "run_commands/built-ins/built_ins.h"
# include "run_commands/execute_command/execute_command.h"
# include "run_commands/set_io/set_io.h"
# include "prompt/prompt.h"
# include "parsing/parsing.h"
# include "env_vars/env_vars.h"
# include "syntax/handle_syntax.h"
# include "run_commands/heredoc/heredoc.h"
# include "env_vars/env_vars_utils/env_vars_utils.h"
# include "env_vars/env_vars_utils/lst_env_vars_ordered/lst_env_vars_ordered.h"
# include "gnl/get_next_line/get_next_line.h"
# include "stdin_func/stdin_func.h"

void	print_args_lst(t_args_lst	*ptr);
void	print_split(char **s);
#endif
