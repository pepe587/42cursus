/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:16:23 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/12/08 13:33:09 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*current;
	t_list	*aux;

	aux = *stack_a;
	current = *stack_a;
	*stack_a = (*stack_a)->next;
	while (current->next)
		current = current->next;
	current->next = aux;
	current->next->next = NULL;
	ft_printf("ra\n");
}

void	rb(t_list **stack_b)
{
	t_list	*current;
	t_list	*aux;

	aux = *stack_b;
	current = *stack_b;
	*stack_b = (*stack_b)->next;
	while (current->next)
		current = current->next;
	current->next = aux;
	current->next->next = NULL;
	ft_printf("rb\n");
}
