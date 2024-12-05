/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars_to_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:44:53 by feguimar          #+#    #+#             */
/*   Updated: 2024/11/29 19:15:02 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	expand_vars_to_string(char *dst, char *src)
{
	int		i;
	int		j;
	int		var_index;
	char	*var_value;

	i = 0;
	j = 0;
	while(src[j] != '\0')
	{
		if (src[j] == '$')
		{
			var_value = get_var_value_heredoc(src, j);
			var_index = 0;
			while(var_value[var_index] != '\0')
				dst[i++] = var_value[var_index++];
			j++;
			while(not_end_env_var(src[j]))
				j++;
		}
		else
		{
			dst[i++] = src[j++];
		}
	}
	dst[i++] = '\n';
	dst[i] = '\0';
}