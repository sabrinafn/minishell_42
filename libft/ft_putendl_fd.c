/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  feguimar < feguimar@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 06:08:23 by  feguimar         #+#    #+#             */
/*   Updated: 2023/10/28 17:33:50 by  feguimar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	size;

	if (s == NULL)
		return ;
	size = ft_strlen(s);
	write(fd, s, size);
	write(fd, "\n", 1);
}
