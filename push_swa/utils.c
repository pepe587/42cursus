/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:08:56 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/12/09 11:38:35 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_sorted(t_list *stack)
{
	t_list	*current;

	if (!stack)
		return (1);
	current = stack;
	while (current->next)
	{
		if ((long)current->content > (long)current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	put_index_and_pos(t_list **stack)
{
	t_list	*head;
	t_list	*current;
	int		index;
	int		pos;

	pos = 1;
	head = *stack;
	while (head)
	{
		current = *stack;
		index = 1;
		while (current)
		{
			if ((long)head->content > (long)current->content)
				index++;
			current = current->next;
		}
		head->index = index;
		head = head->next;
	}
}

int	ft_strncmp_and_free(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] != '\0' || s2[i] != '\0') && (i < n))
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (free((void *)s1), free((void *)s2), 1);
		else if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (free((void *)s1), free((void *)s2), -1);
		i++;
	}
	return (free((void *)s1), free((void *)s2), 0);
}

void	ft_free_matrix(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
