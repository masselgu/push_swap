/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masselgu <masselgu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 12:47:02 by masselgu          #+#    #+#             */
/*   Updated: 2026/01/18 12:47:53 by masselgu         ###   ########.fr       */
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
	stack -> main_index = stack-> next-> main_index;	
	stack -> next-> main_index = tmp;
}