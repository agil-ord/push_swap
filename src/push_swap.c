/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:45:44 by agil-ord          #+#    #+#             */
/*   Updated: 2023/08/14 16:25:51 by agil-ord         ###   ########.fr       */
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

int ft_init_algo(t_stack *stack_a)
{
	t_stack *stack_b;
	int flag;

	flag = 0;
	stack_b = NULL;
	if (ft_is_sorted(stack_a))
	{
		ft_printf("\nEsta ordenado\n");
		return (1);
	}
	if (ft_lstsize_push(stack_a) == 2)
	{
		ft_sort_two(stack_a);
		return (1);
	}
	return (0);
}

int ft_is_sorted(t_stack *stack_a)
{
	t_stack *tmp;

	tmp = stack_a;
	while (tmp->next)
	{
		if (tmp->index > tmp->next->index)
			//ft_printf("\nNO ordenado\n");
			return (ft_printf("\nNO ordenado\n") ,0);
		tmp = tmp->next;
	}
	//ft_printf("\nEsta ordenado\n");
	return (ft_printf("\nesta ordenado\n"), 1);
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
