/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masselgu <masselgu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:29:12 by masselgu          #+#    #+#             */
/*   Updated: 2026/01/19 16:00:16 by masselgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa");
	ft_putstr("\n");
}

void	sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb");
	ft_putstr("\n");
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pa");
	ft_putstr("\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb");
	ft_putstr("\n");
}

void	ra(t_stack **stack)
{
	rotate(stack);
	ft_putstr("ra");
	ft_putstr("\n");
}

void	rra(t_stack **stack)
{
	reverse_rotate(stack);
	ft_putstr("rra");
	ft_putstr("\n");
}
