/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masselgu <masselgu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:29:51 by masselgu          #+#    #+#             */
/*   Updated: 2026/01/20 10:18:25 by masselgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (1);
	current = stack;
	while (current -> next)
	{
		if (current -> n > current -> next -> n)
			return (0);
		current = current -> next;
	}
	return (1);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size <= 3 && !is_sorted(*stack_a))
		sort_three(stack_a);
	else if (size <= 5 && !is_sorted(*stack_a))
		sort_five(stack_a, stack_b);
	else if (!is_sorted(*stack_a))
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	check_input(argc, argv);
	stack_a = create_stack(argc, argv);
	stack_b = NULL;
	size = get_stack_size(stack_a);
	get_main_index(stack_a, size);
	push_swap(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
