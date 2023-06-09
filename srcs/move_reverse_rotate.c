/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:54:03 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/25 09:23:15 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Performs a reverse rotate operation on the specified stack.
Moves the bottom element to the top of the stack.
@param stack The stack on which the reverse rotate operation is performed.
*/
void	move_reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*prev_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	prev_last = NULL;
	while (last->next != NULL)
	{
		prev_last = last;
		last = last->next;
	}
	prev_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_list **stack)
{
	move_reverse_rotate(stack);
	printf("rra\n");
}

void	rrb(t_list **stack)
{
	move_reverse_rotate(stack);
	printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	move_reverse_rotate(stack_a);
	move_reverse_rotate(stack_b);
	printf("rrr\n");
}
