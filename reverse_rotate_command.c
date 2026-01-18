/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masselgu <masselgu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 12:46:56 by masselgu          #+#    #+#             */
/*   Updated: 2026/01/18 12:56:27 by masselgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_stack **stack)
{
    t_stack *last;
    t_stack *before_last;

    if (!stack || !(*stack) || !(*stack) -> next)
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