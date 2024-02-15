/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:33:41 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/12/05 21:34:11 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrx(t_list **stack, int x)
{
	t_list	*new_head;
	t_list	*head;
	t_list	*current;

	current = *stack;
	new_head = *stack;
	head = *stack;
	while (new_head->next)
		new_head = new_head->next;
	while (current->next != new_head)
		current = current->next;
	current->next = NULL;
	new_head->next = head;
	*stack = new_head;
	if (x == 1)
		ft_printf("rra\n");
	else if (x == 2)
		ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rrx(stack_a, 0);
	rrx(stack_b, 0);
	ft_printf("rrr\n");
}
