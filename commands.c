/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masselgu <masselgu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 12:47:02 by masselgu          #+#    #+#             */
/*   Updated: 2026/01/19 11:53:54 by masselgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack -> next)
		return ;
	tmp = stack -> n;
	stack -> n = stack -> next -> n;
	stack -> next -> n = tmp;
	tmp = stack -> main_index;
	stack -> main_index = stack -> next -> main_index;
	stack -> next -> main_index = tmp;
}

void	push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*tmp;

	if (!stack_from || !(*stack_from))
		return ;
	tmp = *stack_from;
	*stack_from = (*stack_from)-> next;
	tmp -> next = *stack_to;
	*stack_to = tmp;
}

void	rotate(t_stack **stack)
{
	t_stack	*ex_top;
	t_stack	*bottom;

	if (!stack || !(*stack) || !(*stack)-> next)
		return ;
	ex_top = *stack;
	*stack = (*stack)-> next;
	bottom = *stack;
	while (bottom -> next)
		bottom = bottom ->next;
	ex_top -> next = NULL;
	bottom -> next = ex_top;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!stack || !(*stack) || !(*stack)-> next)
		return ;
	last = *stack;
	while (last -> next)
		last = last -> next;
	before_last = *stack;
	while (before_last -> next -> next)
		before_last = before_last -> next;
	last -> next = *stack;
	*stack = last;
	before_last -> next = NULL;
}
