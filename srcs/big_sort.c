/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:57:55 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/25 10:15:53 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
Compares the move costs of the first and last nodes in stack_b and returns
the node with the lower cost.
@param stack_b   The stack to compare.
@param best_rank The rank to consider.
@return          The node with the lower cost.
*/
t_list	*compare_cost(t_list **stack_b, int best_rank)
{
	t_list	*first_node;
	t_list	*last_node;

	first_node = find_first_node_stack_b(stack_b, best_rank);
	last_node = find_last_node_stack_b(stack_b, best_rank);
	if (first_node != NULL && last_node != NULL
		&& first_node->cost <= last_node->cost)
		return (first_node);
	else
		return (last_node);
}

/*
Finds the best node in stack_b to move to stack_a based on their move costs
and ranks.
@param stack_a The destination stack.
@param stack_b The source stack.
*/
void	find_best_node_stack_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*highest_rank;
	t_list	*best_node;
	int		best_rank;

	calculate_move_cost(*stack_b);
	count_steps(*stack_b);
	highest_rank = find_highest_rank(stack_b);
	best_rank = ft_lstlast(*stack_a)->rank;
	best_node = compare_cost(stack_b, best_rank);
	if (highest_rank != NULL && best_node != NULL
		&& highest_rank->cost <= best_node->cost)
		highest_rank = best_node;
	if (highest_rank != NULL && highest_rank->steps >= 0)
		while (highest_rank != (*stack_b))
			rb(stack_b);
	else
		while (highest_rank != (*stack_b))
			rrb(stack_b);
	pa(stack_b, stack_a);
}

/*
Checks and adjusts the bottom elements of stack_a if necessary.
@param stack_a The stack to check.
*/
void	check_bottom(t_list **stack_a)
{
	if (ft_lstlast(*stack_a)->rank == (*stack_a)->rank - 1)
		rra(stack_a);
}

/**
Fills the bottom of stack_a under the biggest rank.
@param stack_a The first stack.
@param stack_b The second stack.
@param highest_rank The node with the highest rank in stack_a.*/
void	fill_bottom(t_list **stack_a, t_list **stack_b, t_list *highest_rank)
{
	// check_bottom(stack_a);
	if (ft_lstlast(*stack_a) == highest_rank)
	{
		pa(stack_b, stack_a);
		if ((*stack_a)->rank != (*stack_a)->next->rank - 1)
			ra(stack_a);
		// check_bottom(stack_a);
	}
	if ((*stack_b) != NULL && (*stack_b)->rank == (*stack_a)->rank - 1)
	{
		pa(stack_b, stack_a);
		// check_bottom(stack_a);
	}
	if (((*stack_b) != NULL
			&& (*stack_b)->rank > ft_lstlast(*stack_a)->rank)
		|| (ft_lstlast(*stack_a) == highest_rank))
	{
		pa(stack_b, stack_a);
		ra(stack_a);
		// check_bottom(stack_a);
	}
	check_bottom(stack_a);
}

/*
It iteratively selects the best node from stack_a and moves it to stack_b
while maintaining the order based on the chunks.
@param stack_a The first stack.
@param stack_b The second stack.
*/
void	big_sort(t_list **stack_a, t_list **stack_b)
{
	int		chunks;
	t_list	*highest_rank;

	while (ft_lstsize(*stack_a) > 0)
	{
		chunks = find_small_chunk(*stack_a) + 1;
		find_best_node(stack_a, stack_b, chunks);
		if ((*stack_b)->next != NULL
			&& ((*stack_b)->chunk < (*stack_b)->next->chunk))
			rb(stack_b);
	}
	push_biggest_rank_stack_b(stack_a, stack_b);
	highest_rank = ft_lstlast(*stack_a);
	while (ft_lstsize(*stack_b) > 0)
	{
		fill_bottom(stack_a, stack_b, highest_rank);
		// check_bottom(stack_a);
		find_best_node_stack_b(stack_a, stack_b);
		check_bottom(stack_a);
	}

}

