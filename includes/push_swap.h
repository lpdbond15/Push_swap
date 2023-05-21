/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:06:03 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/20 15:51:50 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				rank;
	int				cost;
	int				steps;
	int				chunk;
	struct s_list	*next;
}					t_list;
void				move_swap(t_list **stack);
void				sa(t_list **stack);
void				sb(t_list **stack);
void				ss(t_list **stack_a, t_list **stack_b);
void				move_rotate(t_list **stack);
void				ra(t_list **stack);
void				rb(t_list **stack);
void				rr(t_list **stack_a, t_list **stack_b);
void				move_reverse_rotate(t_list **stack);
void				rra(t_list **stack);
void				rrb(t_list **stack);
void				rrr(t_list **stack_a, t_list **stack_b);
void				move_push(t_list **stack_from, t_list **stack_to);
void				pa(t_list **stack_b, t_list **stack_a);
void				pb(t_list **stack_a, t_list **stack_b);
bool				check_if_sorted(t_list *stack);
bool				check_if_int(t_list *stack);
bool				check_for_duplicates(t_list *stack);
void				parsing(t_list *stack);
t_list				*stack_init(int argc, char **argv, t_list *stack);
void				tiny_sort(t_list **stack_a);
void				medium_sort(t_list **stack_a, t_list **stack_b);
void				big_sort(t_list **stack_a, t_list **stack_b);
void				big_sort_stack_b(t_list **stack_a, t_list **stack_b);
t_list				*find_smallest_rank(t_list **stack_a);
void				rank_final(t_list **stack);
int					find_highest_position(t_list *stack);
void				count_steps(t_list *stack);
void				find_best_node(t_list **stack_a, int chunks);
t_list				*find_last_node(t_list **stack, int chunks);
t_list				*find_first_node(t_list **stack, int chunks);
t_list				*find_highest_rank(t_list **stack);
void				error(t_list *stack);
void				free_error(char **array, t_list *stack);
void				chunk_init(t_list **stack_a);
void				calculate_move_cost(t_list *stack);
void				ft_lstfree(t_list *list);
long				ft_atol(const char *str, char **array, t_list *stack);
void				check_for_digit(char *str, char **array, t_list *stack);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
char				**ft_split(char const *s, char c);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(int content);
int					ft_lstsize(t_list *lst);
size_t				ft_strlen(const char *s);
int					ft_isdigit(int c);
void				ft_putstr_fd(char *s, int fd);
int					find_small_chunk(t_list *stack);
void	better_big_sort(t_list **stack_a, t_list **stack_b);


#endif
