/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masselgu <masselgu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:21:17 by masselgu          #+#    #+#             */
/*   Updated: 2026/01/18 14:01:40 by masselgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    error_msg()
{
    write(1, "Error\n", 7);
    exit(1);
}

static int  len_strs(char **strs)
{
    int i;

    i = 0;
    while (strs[i])
        i++;
    return (i);
}

static int  ft_isdigit (char c)
{
    if (!(c >= '0' && c <= '9'))
        return (0);
    return (1);
}

static int  check_duplicate (char **strs)
{
    int i;
    int j;
    int len;

    i = 0;
    len = len_strs(strs);
    while (i < len)
    {
        j = i + 1;
        while (j < len)
        {
            if (ft_atoi(strs[i]) == ft_atoi(strs[j]))
                return (0);
            j++;   
        }   
        i++;
    }
    return (1);
}

static int  check_nbr(char *s)
{
    int i;

    i = 0;
    if (s[i] == '-' || s[i] == '+')
        i++;
    while (s[i])
    {
        if (!ft_isdigit(s[i]))
            return (0);
        i++;
    }
    return (1);
}

void    check_input(int ac, char **av)
{
    int     i;
    long    tmp_nbr;
    char    **tmp_array;

    i = 0;
    if (ac == 2)
        tmp_array = ft_split(av[1], ' ');
    else
        tmp_array = av + 1;
    while(tmp_array[i])
    {
        if (!check_nbr(tmp_array[i]))
            error_msg();
        tmp_nbr = ft_atoi(tmp_array[i]);
        if (tmp_nbr > 2147483647 || tmp_nbr < -2147483648)
            error_msg();
        i++;
    }
    if (!check_duplicate(tmp_array))
        error_msg();
    if (ac == 2)
        ft_free(tmp_array);
}
