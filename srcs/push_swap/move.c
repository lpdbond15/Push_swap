#include "../../includes/push_swap.h"

void move_swap(t_list **stack) {
  t_list *node_a;
  t_list *node_b;

  if (*stack == NULL || (*stack)->next == NULL)
    return;
  node_a = *stack;
  node_b = node_a->next;
  node_a->next = node_b->next;
  node_b->next = node_a;
  *stack = node_b;
}

void sa(t_list **stack) {
  move_swap(stack);
  printf("sa\n");
}

void sb(t_list **stack) {
  move_swap(stack);
  printf("sb\n");
}

void ss(t_list **stack_a, t_list **stack_b) {
  move_swap(stack_a);
  move_swap(stack_b);
  printf("ss\n");
}

void move_push(t_list **stack_from, t_list **stack_to) {

  t_list *tmp;

  if (*stack_from == NULL)
    return;
  tmp = (*stack_from)->next;
  (*stack_from)->next = *stack_to;
  *stack_to = *stack_from;
  *stack_from = tmp;
}

void pa(t_list **stack_b, t_list **stack_a) {
  move_push(stack_b, stack_a);
  printf("pa\n");
}

void pb(t_list **stack_a, t_list **stack_b) {
  move_push(stack_a, stack_b);
  printf("pb\n");
}

void move_rotate(t_list **stack) {
  t_list *first;
  t_list *last;

  if (*stack == NULL || (*stack)->next == NULL)
    return;
  first = *stack;
  *stack = (*stack)->next;
  last = *stack;
  while (last->next != NULL)
    last = last->next;
  last->next = first;
  first->next = NULL;
}

void ra(t_list **stack) {
  move_rotate(stack);
  printf("ra\n");
}

void rb(t_list **stack) {
  move_rotate(stack);
  printf("rb\n");
}

void rr(t_list **stack_a, t_list **stack_b) {
  move_rotate(stack_a);
  move_rotate(stack_b);
  printf("rr\n");
}

void move_reverse_rotate(t_list **stack) {
  t_list *last;
  t_list *prev_last;

  if (*stack == NULL || (*stack)->next == NULL)
    return;
  last = *stack;
  prev_last = NULL;
  while (last->next != NULL) {
    prev_last = last;
    last = last->next;
  }
  prev_last->next = NULL;
  last->next = *stack;
  *stack = last;
}

void rra(t_list **stack) {
  move_reverse_rotate(stack);
  printf("rra\n");
}

void rrb(t_list **stack) {
  move_reverse_rotate(stack);
  printf("rrb\n");
}

void rrr(t_list **stack_a, t_list **stack_b) {
  move_reverse_rotate(stack_a);
  move_reverse_rotate(stack_b);
  printf("rrr\n");
}
