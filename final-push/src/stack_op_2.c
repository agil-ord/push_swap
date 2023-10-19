/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:34:50 by agil-ord          #+#    #+#             */
/*   Updated: 2023/10/19 13:47:32 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_read_args(t_stack **stack, int ac, char **av)
{
	int	i;

	if (ac > 2 || (ac == 2 && ft_check_input(av[1])
			&& ft_max_min(ft_atol(av[1]))))
	{
		i = 1;
		while (i < ac)
			if (!ft_check_input(av[i++]))
				return (ft_putstr_fd("Error\n", 2), 99);
		if (!ft_args_numbers(stack, ac, av))
			return (ft_free_stack(stack), ft_putstr_fd("Error\n", 2), 255);
		else
			return (0);
	}
	if (ac == 2)
		if (!ft_args_string(stack, ac, av))
			return (ft_free_stack(stack), ft_putstr_fd("Error\n", 2), 255);
	if (ac == 1)
		return (0);
	return (0);
}

int	ft_max_min(long nb)
{
	if (nb >= INT_MIN && nb <= INT_MAX)
	{
		return (1);
	}
	else
		return (0);
}

int	ft_args_numbers(t_stack **stack, int ac, char **av)
{
	int		i;
	long	nb;

	i = 1;
	while (i < ac)
	{	
		if (!ft_check_input(av[ac - i]))
			return (ft_free_stack(stack), 0);
		nb = ft_atol(av[ac - i++]);
		if (ft_max_min(nb) && !ft_find_data_in_stack(nb, *stack))
		{
			ft_newNode(stack, nb, 0);
		}
		else
		{
			return (ft_free_stack(stack), 0);
		}
	}
	return (1);
}

int	ft_args_string(t_stack **stack, int ac, char **av)
{
	char	**arr;
	int		i;
	long	nb;
	int		gate;

	(void)ac;
	i = 0;
	gate = 0;
	arr = ft_split(av[1], ' ');
	while (arr[i])
		i++;
	while (--i > -1)
	{	
		if (!ft_check_input(arr[i]))
			return (ft_free_stack(stack), ft_free_array(arr), 0);
		nb = ft_atol(arr[i]);
		if (ft_max_min(nb) && !ft_find_data_in_stack(nb, *stack))
		{
			ft_newNode(stack, nb, 0);
			gate = 1;
		}
		else
			return (ft_free_array(arr), ft_free_stack(stack), 0);
	}
	return (ft_free_array(arr), gate);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] && array[i++][0] != '\0')
		free(array[i - 1]);
	free(array);
}	
