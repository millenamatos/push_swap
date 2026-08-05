/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 18:07:28 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/08/05 12:01:09 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node		*top;
	int			size;
}					t_stack;

/*   ------------STACK UTILS------------ */

t_node	*create_node(int value);
void	stack_add_back(t_node **stack, t_node *new_node);
void	free_stack(t_node **stack);

/*   ----------PARSING FUNCTIONS-------- */

void	parse_args(char *arg, t_node **stack);
long	ft_atoi(const char *str, int *error);
char	**ft_split(char const *s, char c);
void	free_split(char **split);

/*   -------------OPERATIONS------------ */

void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

/*   -------------ALGORITHMS------------ */

void	selection_sort(t_stack *stack_a, t_stack *stack_b);

#endif
