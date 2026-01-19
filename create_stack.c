/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masselgu <masselgu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:29:37 by masselgu          #+#    #+#             */
/*   Updated: 2026/01/19 11:57:58 by masselgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_main_index(t_stack *stack_a, int size)
{
	t_stack	*tmp;
	t_stack	*max;
	int		i;

	if (!stack_a)
		return ;
	i = size;
	while (i > 0)
	{
		tmp = stack_a;
		max = NULL;
		while (tmp)
		{
			if (tmp -> main_index == 0 && (!max || tmp -> n > max -> n))
				max = tmp;
			tmp = tmp -> next;
		}
		if (max)
			max -> main_index = i;
		i--;
	}
}

int	get_stack_size(t_stack *stack)
{
	int		size;
	t_stack	*current;

	size = 0;
	current = stack;
	while (current)
	{
		size++;
		current = current -> next;
	}
	return (size);
}

static t_stack	*find_last_node(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head -> next)
		head = head -> next;
	return (head);
}

static void	add_node(t_stack **head, int nbr)
{
	t_stack	*node;
	t_stack	*last;

	if (!head)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node -> n = nbr;
	node -> main_index = 0;
	node -> next = NULL;
	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	last = find_last_node(*head);
	last -> next = node;
}

t_stack	*create_stack(int ac, char **av)
{
	t_stack	*a;
	char	**tmp;
	int		i;

	a = NULL;
	i = 0;
	if (ac == 2)
		tmp = ft_split(av[1], ' ');
	else
	{
		i = 1;
		tmp = av;
	}
	while (tmp[i])
	{
		add_node(&a, ft_atoi(tmp[i]));
		i++;
	}
	if (ac == 2)
		ft_free(tmp);
	return (a);
}
