/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:56:38 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/12/14 18:23:01 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_or_rra(t_list **stack)
{
	int		len;
	t_list	*iter;
	int		count;

	count = 0;
	iter = *stack;
	len = 0;
	while (iter && len)
		iter = iter->next;
	iter = *stack;
	while (iter->index != 1)
	{
		count++;
		iter = iter->next;
	}
	if (count == 1)
		sa(*stack);
	else if (count <= (len / 2))
		ra(stack);
	else
		rrx(stack, 1);
}

void	radix(t_list **stack_a, t_list **stack_b, int argc)
{
	int	bits;
	int	i;
	int	j;

	bits = 0;
	i = 0;
	while (argc >> ++bits)
		;
	while (i < bits && !check_is_sorted(*stack_a))
	{
		j = 0;
		while (j++ < argc && !check_is_sorted(*stack_a))
		{
			if (*stack_a)
			{
				if ((*stack_a)->index & (i << 1))
					ra(stack_a);
				else
					pb(stack_a, stack_b);
			}
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}

void	radix_small_stack(t_list **stack_a, t_list **stack_b)
{
	while (!check_is_sorted(*stack_a))
	{
		if ((*stack_a)->index != 1)
		{
			put_index_and_pos(stack_a);
			if ((*stack_a)->index == 2 && (*stack_a)->next->index == 1)
				sa(*stack_a);
			else
				ra_or_rra(stack_a);
		}
		else
			pb(stack_a, stack_b);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}
