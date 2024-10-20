/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:03:28 by sabrifer          #+#    #+#             */
/*   Updated: 2024/10/17 20:55:49 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_args_lst
{
	char *arg;               // single argument
	int type;                // type of argument - need to be implemented
	struct s_args_lst *next; // points to the next argument
}			t_args_lst;

typedef struct s_quotes
{
	int		single_count;
	int		double_count;
}			t_quotes;

enum		e_args
{
	STRING,
	OPERATORS,
};

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s == NULL || start >= ft_strlen(s))
	{
		sub = (char *)malloc(1);
		if (sub == NULL)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

void	create_node(t_args_lst **args_lst, const char *str, int start, int len)
{
	t_args_lst	*new;
	t_args_lst	*temp;
	enum e_args	type;

	new = (t_args_lst *)malloc(sizeof(t_args_lst));
	temp = *args_lst;
	new->arg = ft_substr(str, start, len);
	new->type = STRING;
	// printf("string = [%s]\n", ft_substr(str, start, len));
	if (temp == NULL)
		*args_lst = new;
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
}

char	*ft_strchr(const char *s, int c)
{
	char	*ret;

	ret = (char *)s;
	while (1)
	{
		if (*ret == (char)c)
			return (ret);
		if (*ret == '\0')
			break ;
		ret++;
	}
	return (NULL);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	len;
	size_t	j;

	if (!s || !reject)
		return (0);
	len = 0;
	while (s[len])
	{
		j = 0;
		while (reject[j])
		{
			if (s[len] == reject[j])
				return (len);
			j++;
		}
		len++;
	}
	return (len);
}

t_args_lst	*ft_lst_split(char *str)
{
	t_args_lst	*lst;
	int			i;
	int			j;

	lst = NULL;
	i = 0;
	j = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		j = ft_strcspn(str + i, " \'\"\0");
		if (str[i] != '\0')
		{
			if ((str + i)[j] != '\0')
				j++;
			create_node(&lst, str, i, j);
			i = i + j;
		}
	}
	return (lst);
}

int	count_len_needed(t_args_lst *lst)
{
	static int	count;
	int	i;

	count = 0;
	i = 0;

	while (new_lst)
	{
		if (ft_strchr(new_lst->arg, ' '))

		new_lst = new_lst->next;
	}
}
// void	create_node(t_args_lst **args_lst, const char *str, int start, int len)
t_args_lst	*split_final(t_args_lst **lst)
{
	t_args_lst	*split;
	t_args_lst	*new_lst;
	char		*str;
	int			i;
	int			j;

	split = NULL;
	new_lst = *lst;
	i = 0;
	j = 0;
	while (new_lst)
	{
		if (!ft_strchr(new_lst->arg, '\'') && !ft_strchr(new_lst->arg, '\"'))
		{
			if (ft_strchr(new_lst->arg))
			split->arg = ft_strjoin(split->arg, "");

			count_len_needed)(new_lst);
			//create_node(&split, new_lst->arg, i, j);

		}
	}
}

int	main(void)
{
	t_args_lst	*split;
	t_args_lst	*new_split;
	char		*str;
	int			i;

	// str = "echo \"p\"a\'\'\'\'\'ABCDE\"F\"G\'\"ra\"\'b\'\"\"\'\'\"\"\'\'\'ens\'";
	str = "echo bom dia 'mundo'";
	printf("[%s]\n", str);
	split = ft_lst_split(str);
	i = 0;
	while (split)
	{
		printf("node[%d] - split->arg:[%s]\n", i, split->arg);
		split = split->next;
		i++;
	}
//	new_split = split_final(&split);
}
