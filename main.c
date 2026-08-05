/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 18:43:57 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/08/05 11:57:11 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int sizelist(t_node *lista)
{
	int size;

	size = 0;
	while(lista)
	{
		size++;
		lista = lista->next;
	}
	return (size);
}

int	main(int argc, char **argv)
{
	t_node	*tmp;
	t_stack	*stack_b;
	t_stack *stack_a;
	t_node	*lista;
	int		i;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	lista = NULL;
	i = 1;
	while (i < argc)
	{
		parse_args(argv[i], &lista);
		i++;
	}
	tmp = lista;
	while (tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	stack_a->top = lista;
	stack_a->size = sizelist(lista);
	selection_sort(stack_a, stack_b);
	tmp = stack_a->top;
	printf("\n");
	while (tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
	free(stack_a);
	free(stack_b);
	return (0);
}
