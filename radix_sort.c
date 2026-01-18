/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masselgu <masselgu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 11:56:21 by masselgu          #+#    #+#             */
/*   Updated: 2026/01/18 14:01:24 by masselgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_max_bits(t_stack *stack)
{
    int max;
    t_stack *s;
    int bits;

    max = 0;
    s = stack;
    while (s)
    {
        if (s -> main_index > max)
            max = s -> main_index;
        s = s -> next;
    }
    bits = 0;
    while ((max >> bits) != 0)
        bits++;
    return bits;
}

void radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int i;
    int j;
    int size;
    int max_bits;

    if (!stack_a || !(*stack_a))
        return ;

    size = get_stack_size(*stack_a);
    max_bits = get_max_bits(*stack_a);

    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if (((*stack_a) -> main_index >> i) & 1)
                rotate_move(stack_a, NULL, "ra");
            else
                swap_move(stack_a, stack_b, "pb");
            j++;
        }
        while (*stack_b)
            swap_move(stack_a, stack_b, "pa");
        i++;
    }
}