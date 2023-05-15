/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:06:03 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/15 15:38:02 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft42/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	move_swap(t_list **stack);
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	move_push(t_list **stack_from, t_list **stack_to);
void	free_error(char **array, t_list *stack);
void	print_stack(t_list *stack);
int		check_if_sorted(t_list *stack);
void	check_for_errors(t_list *stack);
t_list	*stack_init(int argc, char **argv, t_list *stack);
void	move_rotate(t_list **stack);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	move_reverse_rotate(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
void	move_reverse_rotate(t_list **stack);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_b, t_list **stack_a);
void	pb(t_list **stack_a, t_list **stack_b);
void	tiny_sort(t_list **stack_a);
t_list	*find_smallest_rank(t_list **stack_a);
int		give_index(t_list *stack);
void	sort_five(t_list **stack_a, t_list **stack_b);
t_list	*find_best_rank(t_list **stack_a, int key_nbr);
void	rank_final(t_list **stack);
int		find_highest_position(t_list *stack);
void	find_best_node(t_list **stack, int chunks);
void	big_sort(t_list **stack_a, t_list **stack_b);
t_list	*find_last_node(t_list **stack, int chunks);
t_list	*find_first_node(t_list **stack, int chunks);
t_list	*find_highest_rank(t_list **stack);

#endif
