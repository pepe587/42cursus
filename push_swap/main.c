/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:32:08 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/12/10 13:39:37 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

static int	num_of_substr(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	ft_free_list(t_list	*list, char **argv)
{
	t_list	*temp;

	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
	if (check_errors(argv, 0) == 2)
		ft_free_matrix(argv);
}

void	arg_to_stack(t_list *stack, char *num)
{
	t_list		*new_node;
	t_list		*current;

	current = stack;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	while (current->next)
		current = current->next;
	new_node->content = (void *)(long)ft_atoi(num);
	new_node->next = NULL;
	current->next = new_node;
}

void	stack_a_init(char **argv, t_list *stack, int i)
{
	if (i == 0)
		i = 2;
	stack->content = (void *)(long)ft_atoi(argv[i - 1]);
	stack->next = NULL;
	while (argv[i])
	{
		arg_to_stack(stack, argv[i]);
		i++;
	}
	put_index_and_pos(&stack);
}

/*void	ft_leaks()
{
	system("leaks -q push_swap");
}*/

/*Check memory leaks with this line "atexit(ft_leaks);" */

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		type;

	if (argc < 2)
		return (0);
	if (check_errors(argv, 1) == 0)
		return (ft_printf("Error\n"), 0);
	if (check_errors(argv, 1) == 2)
	{
		argv = ft_split(argv[1], 32);
		argc = num_of_substr(argv) + 1;
		if (check_errors(argv, 0) == 0)
			return (ft_printf("Error\n"), 0);
		type = 1;
	}
	stack_a = malloc(sizeof(t_list));
	if (!stack_a)
		return (0);
	stack_b = 0;
	stack_a_init(argv, stack_a, type);
	if (check_is_sorted(stack_a) == 1)
		return (ft_free_list(stack_a, argv), 1);
	sort(argc, &stack_a, &stack_b);
	ft_free_list(stack_a, argv);
}
