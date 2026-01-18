/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masselgu <masselgu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 13:27:00 by masselgu          #+#    #+#             */
/*   Updated: 2026/01/18 13:29:11 by masselgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_index(t_stack *stack)
{
	int		max_id;
	t_stack	*current;

	if (!stack)
		return (0);
	max_id = stack -> main_index;
	current = stack;
	while (current)
	{
		if (current -> main_index > max_id)
			max_id = current -> main_index;
		current = current -> next;
	}
	return (max_id);
}

void	sort_three(t_stack **stack)
{
	int	max_id;

	if (!stack || !(*stack) || !(*stack) -> next)
	    return;
	max_id = get_max_index(*stack);
	if ((*stack) -> main_index == max_id)
		rotate_move(stack, NULL, "ra");
	else if ((*stack) -> next -> main_index == max_id)
		rotate_move(stack, NULL, "rra");
	if ((*stack) -> main_index > (*stack) -> next -> main_index)
		swap_move(stack, NULL, "sa");
}