/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masselgu <masselgu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:29:57 by masselgu          #+#    #+#             */
/*   Updated: 2026/01/20 13:20:15 by masselgu         ###   ########.fr       */
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

int		get_stack_size(t_stack *stack);
t_stack	*create_stack(int argc, char **argv);
void	get_main_index(t_stack *stack_a, int size);
int		is_sorted(t_stack *stack);

void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

long	ft_atoi(const char *str);
void	ft_putstr(char *str);
void	free_stack(t_stack **head);

char	*ft_substr(char const *s, unsigned int start, size_t len);
void	error_msg(void);
char	**ft_split(char const *s, char c);
void	ft_free(char **arr);
void	check_input(int argc, char **argv);

void	pa(t_stack **stack_a, t_stack **stack_b);
void	sb(t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	ra(t_stack **stack);
void	rra(t_stack **stack);
void	swap(t_stack *stack);
void	push(t_stack **stack_from, t_stack **stack_to);
void	reverse_rotate(t_stack **stack);
void	rotate(t_stack **stack);
#endif