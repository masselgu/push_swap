/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masselgu <masselgu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:30:06 by masselgu          #+#    #+#             */
/*   Updated: 2026/01/24 13:25:23 by masselgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}

void	free_stack(t_stack **head)
{
	t_stack	*tmp;

	if (!head || !*head)
		return ;
	while (*head)
	{
		tmp = (*head)-> next;
		free (*head);
		*head = tmp;
	}
	*head = NULL;
}

long	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > (9223372036854775807 - (str[i] - '0')) / 10)
			error_msg();
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	ft_free(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	error_msg(void)
{
	write(2, "Error\n", 7);
	exit(1);
}
