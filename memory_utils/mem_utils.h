/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:53:39 by fernando          #+#    #+#             */
/*   Updated: 2024/12/06 17:33:08 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_UTILS_H
# define MEM_UTILS_H

# include "../minishell.h"

void	add_to_mem_list(const char *name, void *ptr);
void	free_all(void);
void	ft_free(void **ptr);
void	*ft_maloc(size_t size, const char *name);
void	print_all_mem(void);

// functions to free args list
void	free_lst(t_args_lst *node);
void	free_args_lst(t_args_lst **args_lst);

// function to free split
void	ft_free_split(char **arr);
#endif
