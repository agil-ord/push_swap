/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:08:36 by agil-ord          #+#    #+#             */
/*   Updated: 2023/07/31 12:33:11 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_correct_input(char **cadena)
{
	int	i;
	int	n_zeros;

	i = 0;
	n_zeros = 0;
	ft_printf("\nEntra a correct input\n");
	while (cadena[i])
	{
		if (!ft_is_num(cadena[i]))
		{
			ft_printf("\nError, no es correct input num");
			return (0);
		}
		n_zeros += ft_is_zero(cadena[i]);
		i++;
	}
	if (n_zeros > 1)
		return (ft_printf("\nError en comprobar 0"), 0);
	if (ft_c_duplicate(cadena))
		return (ft_printf("\nError en comprobar dupli"), 0);
	return (1);
}


int	main(int ac, char **av)
{
	int		*array_stack_a;
	int		j;
	int		i;
	int		valido;
	char	**array_stack_other;

	valido = 0;
	array_stack_other = NULL;
	array_stack_a = malloc(sizeof(int) * (ac - 1));
	if (ac >= 2)
	{	
		if (ac == 2)
			array_stack_other = ft_split(av[1], ' ');
		else
		{
			array_stack_other = malloc(sizeof(char *) * (ac - 1));
			i = 1;
			j = 0;
			while (av[i])
			{
				array_stack_other[j] = av[i];
				i++;
				j++;
			}
		}
		if (ft_correct_input(array_stack_other))
		{
			ft_printf("\nProbando nuevo main\n");
			valido = 1;
		}
		j = 0;
		if (valido == 1)
		{	
			while (array_stack_other[j])
			{
				array_stack_a[j] = ft_atol_push(array_stack_other[j]);
				printf("\n%d\n", array_stack_a[j]);
				j++;
			}
			valido = 0;
		}
		ft_printf("\nUltima comprobacion de duplicados\n");
		if (ft_n_duplicate(array_stack_a, j))
			return (ft_printf("\nError en comprobar duplicados segunda vez"), 0);
		ft_printf("\nTermina bien\n");
	}
	else
	{
		ft_printf("\nError\n");
		return (0);
	}
}
