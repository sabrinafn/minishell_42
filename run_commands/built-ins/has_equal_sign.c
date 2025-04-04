/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_equal_sign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:39:52 by fernando          #+#    #+#             */
/*   Updated: 2024/12/02 22:13:24 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	has_equal_sign(char *str)
{
	if (ft_strchr(str, '=') == NULL)
		return (0);
	return (1);
}
