#include "push_swap.h"

void sa(t_stack *stack_a) 
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

void ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a);
    sb(stack_b);
}

void pa(t_stack *stack_a, t_stack *stack_b) 
{
    t_node *temp;

    if (!stack_b || stack_b->size == 0)
        return ;
    temp = stack_b->top; // = 1
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

void ra(t_stack *stack_a) 
{
    t_node *first;
    t_node *last;

    if (!stack_a || stack_a->size < 2)
        return ; 
    first = stack_a->top; 
    stack_a->top = first->next; 
    last = stack_a->top; 
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;
}

void rb(t_stack *stack_b)
{
    t_node *first;
    t_node *last;

    if (!stack_b || stack_b->size < 2)
        return ;
    first = stack_b->top;
    stack_b->top = first->next;
    last = stack_b->top;
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

void rra(t_stack *stack_a)
{
    t_node *last;
    t_node *second_last;

    if (!stack_a || stack_a->size < 2)
        return ;
    last = stack_a->top; // = 1
    second_last = NULL; // = 3
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = stack_a->top;
    stack_a->top = last;
}

void rrb(t_stack *stack_b)
{
    t_node *last;
    t_node *second_last;

    if (!stack_b || stack_b->size < 2)
        return ;
    last = stack_b->top;
    second_last = NULL;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = stack_b->top;
    stack_b->top = last;
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}