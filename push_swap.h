/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 18:07:28 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/08/11 23:16:49 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node		*top;
	int			size;
}					t_stack;

typedef struct s_config
{
	int	strategy;
	int	bench;
	int	count_sa;
	int	count_sb;
	int	count_ss;
	int	count_pa;
	int	count_pb;
	int	count_ra;
	int	count_rb;
	int	count_rr;
	int	count_rra;
	int	count_rrb;
	int	count_rrr;
	int	count_total;
}	t_config;

/*   ------------STACK UTILS------------ */

void	init_stack(t_stack *stack);
t_node	*create_node(int value);
void	stack_add_back(t_stack *stack, t_node *new_node);
void	free_stack(t_stack *stack);

/*   ----------PARSING FUNCTIONS-------- */

void	parse_args(int argc, char **argv, t_stack *stack, t_config config);
int		parse_flag(char *arg, t_config config);
void	parse_number(char *arg, t_stack *stack);
long	ft_atoi(const char *str, int *error);
char	**ft_split(char const *s, char c);
void	free_split(char **split);
void	free_error_exit(t_stack *stack, char **split);

/*   -------------BENCH------------ */

void	print_bench(t_config *config, double mess, char *strat, char *complx);

/*   -------------OPERATIONS------------ */

void	sa(t_stack *stack_a, t_config *config);
void	sb(t_stack *stack_b, t_config *config);
void	ss(t_stack *stack_a, t_stack *stack_b, t_config *config);
void	pa(t_stack *stack_a, t_stack *stack_b, t_config *config);
void	pb(t_stack *stack_a, t_stack *stack_b, t_config *config);
void	ra(t_stack *stack_a, t_config *config);
void	rb(t_stack *stack_b, t_config *config);
void	rr(t_stack *stack_a, t_stack *stack_b, t_config *config);
void	rra(t_stack *stack_a, t_config *config);
void	rrb(t_stack *stack_b, t_config *config);
void	rrr(t_stack *stack_a, t_stack *stack_b, t_config *config);

/*   -------------ALGORITHMS------------ */

double	compute_disorder(t_stack *stack_a);
void	selection_sort(t_stack *stack_a, t_stack *stack_b);
void	organize_stack(t_stack *stack_a);
int		find_position(t_stack *stack_a, int index);
void	rotate_to_top(t_stack *stack_a, int index);
int		has_chunk(t_stack *stack_a, int start, int end);
int		find_chunk_index(t_stack *stack_a, int start, int end);
void	push_chunk(t_stack *stack_a, t_stack *stack_b, int start, int end);
int		get_chunk_size(int size);
void	sort_chunks(t_stack *stack_a, t_stack *stack_b);
int		find_max_index(t_stack *stack_b);
void	rotate_b_to_top(t_stack *stack_b, int index);
void	push_back(t_stack *stack_a, t_stack *stack_b);

#endif
