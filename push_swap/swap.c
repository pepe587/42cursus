/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:34:14 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/11/24 12:41:24 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	sa(t_list *stack_a)
{
	int	*num;

	if (!stack_a || !stack_a->next)
		return ;
	num = (int *)stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = num;
	ft_printf("sa\n");
}

void	sb(t_list *stack_b)
{
	int	*num;

	if (!stack_b || !stack_b->next)
		return ;
	num = (int *)stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = num;
	ft_printf("sb\n");
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	int	*num;
	int	*num1;

	if (stack_a || !stack_a->next)
	{
		num = stack_a->content;
		stack_a->content = stack_a->next->content;
		stack_a->next->content = num;
	}
	if (stack_b || stack_b->next)
	{
		num1 = stack_b->content;
		stack_b->content = stack_b->next->content;
		stack_b->next->content = num;
	}
	ft_printf("ss\n");
}
