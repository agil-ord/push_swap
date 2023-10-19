/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:45:44 by agil-ord          #+#    #+#             */
/*   Updated: 2023/08/13 17:57:06 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_correct_input(char **cadena)
{
	int	i;
	int	n_zeros;

	i = 0;
	n_zeros = 0;
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

char **create_stack_other(int ac, char **av)
{
	char	**array_stack_other;
	int		i;

	array_stack_other = NULL;
	if (ac == 2)
		array_stack_other = ft_split(av[1], ' ');
	else
	{
		array_stack_other = (char **)malloc(sizeof(char *) * (ac - 1));
		i = 1;
		while (av[i])
		{
			array_stack_other[i - 1] = malloc(sizeof(char) * ft_strlen(av[i]));
			array_stack_other[i - 1] = av[i];
			i++;
		}
	}
	return (array_stack_other);
}

//funcion que represente al bucle while de la funcion principal
int process_input_and_push(int *array_stack_a, t_stack **stack_a, char **array_stack_other)
{
    int i = 0;

    while (array_stack_other[i])
    {
        array_stack_a[i] = ft_atol_push(array_stack_other[i]);
        push(stack_a, array_stack_a[i]);
        i++;
    }
	return (i);
}

int	main(int ac, char **av)
{
	int		*array_stack_a;
	int		i;
	t_stack *stack_a;
	char	**array_stack_other;

	array_stack_other = NULL;
	array_stack_a = malloc(sizeof(int) * (ac - 1));
	if (ac >= 2)
	{	
		i = 0;
		array_stack_other = create_stack_other(ac, av);
		if (ft_correct_input(array_stack_other))
		{	
			stack_a = NULL;
			i = process_input_and_push(array_stack_a, &stack_a, array_stack_other);
		}
		if (ft_n_duplicate(array_stack_a, i))
			return (ft_printf("\nError en comprobar duplicados segunda vez"), 0);
		ft_index(stack_a);
		print_stack(stack_a);
		//aqu va el algoritmo de ordenacion es decir a partir de aqui ordenaria
	}
	return (0);
}
