/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masselgu <masselgu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 12:46:58 by masselgu          #+#    #+#             */
/*   Updated: 2026/01/18 12:56:25 by masselgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_stack **stack)
{
    t_stack *ex_top;
    t_stack *bottom;

    if (!stack || !(*stack) || !(*stack) -> next)
        return ;
    ex_top = *stack;
    *stack = (*stack) -> next;
    bottom = *stack;
    while (bottom -> next)
        bottom = bottom->next;
    ex_top -> next = NULL;
    bottom -> next = ex_top;
}