/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masselgu <masselgu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:40:41 by masselgu          #+#    #+#             */
/*   Updated: 2026/01/23 18:27:49 by masselgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	pushed;

	if (!stack_a || !(*stack_a))
		return ;
	pushed = 0;
	while (pushed < 2)
	{
		if ((*stack_a)-> main_index == 1 || (*stack_a)-> main_index == 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
	}
	sort_three(stack_a);
	if ((*stack_b)-> main_index < (*stack_b)-> next -> main_index)
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
