/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:57:54 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/12/09 12:44:46 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_elements(t_list **stack_a)
{
	if ((long)(*stack_a)->content > (long)(*stack_a)->next->content)
	{
		sa(*stack_a);
		if ((long)(*stack_a)->next->content >
			(long)(*stack_a)->next->next->content)
		{
			rrx(stack_a, 1);
			if ((long)(*stack_a)->content > (long)(*stack_a)->next->content)
				sa(*stack_a);
		}
		return ;
	}
	if ((long)(*stack_a)->content > (long)(*stack_a)->next->next->content
	&& (long)(*stack_a)->next->content > (long)(*stack_a)->next->next->content)
		rrx(stack_a, 1);
	if ((long)(*stack_a)->next->content > (long)(*stack_a)->next->next->content)
	{
		rrx(stack_a, 1);
		sa(*stack_a);
	}
}

void	five_elements(t_list **stack_a, t_list	**stack_b, int argc)
{
	while ((*stack_a)->index != 1 && !check_is_sorted(*stack_a))
	{
		ra_or_rra(stack_a);
		put_index_and_pos(stack_a);
	}
	pb(stack_a, stack_b);
	put_index_and_pos(stack_a);
	if (argc == 6)
	{
		while ((*stack_a)->index != 1 && !check_is_sorted(*stack_a))
		{
			put_index_and_pos(stack_a);
			if ((*stack_a)->next->index == 1)
				sa(*stack_a);
			else if ((*stack_a)->index != 1)
				ra_or_rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	three_elements(stack_a);
	pa(stack_a, stack_b);
	if (argc == 6)
		pa(stack_a, stack_b);
}

void	sort(int argc, t_list **stack_a, t_list **stack_b)
{
	if (check_is_sorted(*stack_a) == 1)
		return ;
	else if (argc == 3)
		sa(*stack_a);
	else if (argc == 4)
		three_elements(stack_a);
	else if (argc == 6 || argc == 5)
		five_elements(stack_a, stack_b, argc);
	else if (argc >= 7 && argc <= 41)
		radix_small_stack(stack_a, stack_b);
	else
		radix(stack_a, stack_b, argc - 1);
}
