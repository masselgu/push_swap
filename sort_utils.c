/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masselgu <masselgu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:29:12 by masselgu          #+#    #+#             */
/*   Updated: 2026/01/18 13:29:09 by masselgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_move(t_stack **stack_a, t_stack **stack_b, char *choice)
{
	if (ft_strcmp(choice, "sa") == 0)
		swap(*stack_a);
	else if (ft_strcmp(choice, "sb") == 0)
		swap(*stack_b);
	else if (ft_strcmp(choice, "ss") == 0)
	{
		swap(*stack_a);
		swap(*stack_b);
	}
	if (ft_strcmp(choice, "pa") == 0)
		push(stack_b, stack_a);
	else if (ft_strcmp(choice, "pb") == 0)
		push(stack_a, stack_b);
	ft_putstr(choice);
	ft_putstr("\n");
}

void	rotate_move(t_stack **sa, t_stack **sb, char *choice)
{
	if (ft_strcmp(choice, "ra") == 0)
		rotate(sa);
	else if (ft_strcmp(choice, "rb") == 0)
		rotate(sb);
	else if (ft_strcmp(choice, "rr") == 0)
	{
		rotate(sa);
		rotate(sb);
	}
	else if (ft_strcmp(choice, "rra") == 0)
		reverse_rotate(sa);
	else if (ft_strcmp(choice, "rrb") == 0)
		reverse_rotate(sb);
	else if (ft_strcmp(choice, "rrr") == 0)
	{
		reverse_rotate(sa);
		reverse_rotate(sb);
	}
	ft_putstr(choice);
	ft_putstr("\n");
}