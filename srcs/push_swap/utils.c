/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:54:01 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/14 14:54:02 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <unistd.h>

void	print_stack(t_list *stack)
{
	while (stack != NULL)
	{
		printf("%i\n", stack->content);
		printf("%i\n", stack->index);
		stack = stack->next;
	}
}

void	free_error(char **array, t_list *stack)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	ft_lstclear(&stack);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}
