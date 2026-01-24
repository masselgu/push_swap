/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masselgu <masselgu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 11:56:21 by masselgu          #+#    #+#             */
/*   Updated: 2026/01/23 18:15:53 by masselgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	power_of_two(int n)
{
	int	result;

	result = 1;
	while (n > 0)
	{
		result *= 2;
		n--;
	}
	return (result);
}

static int	get_max_bits(t_stack *stack)
{
	int		max;
	int		bits;
	t_stack	*tmp;

	max = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp-> main_index > max)
			max = tmp-> main_index;
		tmp = tmp-> next;
	}
	bits = 0;
	while (power_of_two(bits) <= max)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;
	int	j;
	int	div;
	int	max_bits;

	if (!stack_a || !*stack_a)
		return ;
	max_bits = get_max_bits(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		div = power_of_two(i);
		while (j < size)
		{
			if (((*stack_a)-> main_index / div) % 2 == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
