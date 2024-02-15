/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:42:03 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/12/10 13:19:58 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	int				index;
}					t_list;

void	sa(t_list *stack_a);
void	sb(t_list *stack_b);
void	ss(t_list *stack_a, t_list *stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rrx(t_list **stack, int x);
void	rrr(t_list **stack_a, t_list **stack_b);
int		check_errors(char **argv, int i);
void	radix(t_list **stack_a, t_list **stack_b, int argc);
int		check_is_sorted(t_list *stack);
void	sort(int argc, t_list **stack_a, t_list **stack_b);
void	put_index_and_pos(t_list **stack);
void	ft_print_lists(t_list *stack_a, t_list *stack_b);
void	ra_or_rra(t_list **stack);
void	radix_small_stack(t_list **stack_a, t_list **stack_b);
int		ft_strncmp_and_free(const char *s1, const char *s2, size_t n);
void	ft_free_matrix(char **map);
#endif