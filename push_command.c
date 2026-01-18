/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masselgu <masselgu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 12:46:53 by masselgu          #+#    #+#             */
/*   Updated: 2026/01/18 12:56:29 by masselgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack *tmp;

	if (!stack_from || !(*stack_from))
		return ;
	tmp = *stack_from;
	*stack_from = (*stack_from) -> next;
	tmp -> next = *stack_to;
	*stack_to = tmp;
}