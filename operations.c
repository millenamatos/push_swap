#include "push_swap.h"

void sa(t_stack *stack_a) //troca os dois primeiros
{
    t_node *first;
    t_node *second;

    if (!stack_a || stack_a->size < 2)
        return ;
    first = stack_a->top;
    second = first->next;
    first->next = second->next;
    second->next = first;
    stack_a->top = second;
}

void sb(t_stack *stack_b)
{
    t_node *first;
    t_node *second;

    if (!stack_b || stack_b->size < 2)
        return ;
    first = stack_b->top;
    second = first->next;
    first->next = second->next;
    second->next = first;
    stack_b->top = second;
}

void pa(t_stack *stack_a, t_stack *stack_b)
{
    t_node *temp;

    if (!stack_b || stack_b->size == 0)
        return ;
    temp = stack_b->top;
    stack_b->top = stack_b->top->next;
    stack_b->size--;

    temp->next = stack_a->top;
    stack_a->top = temp;
    stack_a->size++;
}

void pb(t_stack *stack_a, t_stack *stack_b)
{
    t_node *temp;

    if (!stack_a || stack_a->size == 0)
        return ;
    temp = stack_a->top;
    stack_a->top = stack_a->top->next;
    stack_a->size--;

    temp->next = stack_b->top;
    stack_b->top = temp;
    stack_b->size++;
}