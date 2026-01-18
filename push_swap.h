/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masselgu <masselgu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:29:57 by masselgu          #+#    #+#             */
/*   Updated: 2026/01/18 13:46:12 by masselgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				n;
	int				main_index;
	struct s_stack	*next;
}					t_stack;

int	get_stack_size(t_stack *stack);
t_stack *create_stack(int ac, char **av);
void	get_main_index(t_stack *stack_a, int size);
int	is_sorted(t_stack *stack);

void	swap_move(t_stack **sa, t_stack **sb, char *choice);
void	sort_three(t_stack **stack);
void	rotate_move(t_stack **sa, t_stack **sb, char *choice);

void radix_sort(t_stack **stack_a, t_stack **stack_b);

long	ft_atoi(const char *str);
void	ft_putstr(char *str);
void	free_stack(t_stack **head);

char    **ft_split(char const *s, char c);
int		ft_strcmp(char *s1, char *s2);
void	ft_free(char **arr);
void	check_input(int ac, char **av);

void	swap(t_stack *stack);
void	push(t_stack **stack_from, t_stack **stack_to);
void 	reverse_rotate(t_stack **stack);
void 	rotate(t_stack **stack);
#endif