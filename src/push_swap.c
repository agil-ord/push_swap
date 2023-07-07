/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:23:19 by agil-ord          #+#    #+#             */
/*   Updated: 2023/07/07 13:20:37 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

long	ft_atol_push(const char *str)
{
	int		i;
	int		flag;
	long	result;

	i = 0;
	flag = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result *= 10;
		result += (str[i] - '0');
		i++;
	}
	return (result * flag);
}

//para ver si lo primero es un signo
//devolveria 0 sino se cumple
int	ft_sign(char c)
{
	return (c == '-' || c == '+');
}

int	ft_is_num(char *s)
{
	int	i;

	i = 0;
	if (ft_sign(s[i]) && s[i + 1])
		i++;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	if (s[i] && !ft_isdigit(s[i]))
		return (0);
	return (1);
}

//controlo el caso en que sea 0 o 000 o +/- 0
int	ft_is_zero(char *s)
{
	int	i;

	i = 0;
	while (ft_sign(s[i]))
		i++;
	while (s[i] && s[i] == '0')
		i++;
	if (s[i])
		return (0);
	return (1);
}

int	ft_cmp_str(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] && s2[j] && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}

//compruebo que no haya numeros repetidos
int	ft_n_duplicate(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{	
		j = i + 1;
		while (s[j])
		{
			if (j != i && ft_cmp_str(s[i], s[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

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
	if (ft_n_duplicate(cadena))
		return (ft_printf("\nError en comprobar dupli"), 0);
	return (1);
}

int	main(int ac, char **av)
{
	//t_stack *stack_a;
	int *array_stack_a = malloc(sizeof(int) * (ac - 1));
	int j = 0;
	int i = 1;
	int valido = 0;
	char **array_stack_more_2 = malloc(sizeof(char *) * (ac - 1));
	char **array_stack_other;
	// t_stack *stack_b;

	if (ac == 2)
	{
		array_stack_other = ft_split(av[1], ' ');
		if (ft_correct_input(array_stack_other))
			valido = 1;
		if (valido == 1)
		{	
			while(array_stack_other[j])
			{
				array_stack_a[j] = ft_atol_push(array_stack_other[j]);
				printf("\n%d\n", array_stack_a[j]);
				j++;
			}
			valido = 0;
		}
	}	
	
	else if (ac > 2)
	{
		j = 0;
		while (av[i])
		{
			array_stack_more_2[j] = av[i];
			i++;
			j++;
		}
		if (ft_correct_input(array_stack_more_2))
		{
			//ahora tengo que meter los valores en la pila
			ft_printf("\nconvertimos si ha ido bien\n");
			i = 0;
			j = 0;
			while(array_stack_more_2[i])
			{
				array_stack_a[j] = ft_atol_push(array_stack_more_2[i]);
				i++;
				ft_printf("\n%d\n", array_stack_a[j]);
				j++;
			}	
		}
	}
	else
	{
		ft_printf("\nError\n"); //hay que mandar los errores al algun lado?
		return (0);
	}
}
