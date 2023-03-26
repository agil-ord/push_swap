/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:23:19 by agil-ord          #+#    #+#             */
/*   Updated: 2023/03/26 19:39:52 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!s[i])
		return (0);
	return (1);
}

//compruebo que no haya numeros repetidos
int	ft_n_duplicate(char **s)
{
	int	i;
	int	j;

	i = 1;
	while (s[i])
	{
		j = 1;
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

int	ft_cmp_str(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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
	return (s1 - s2);
}

int	ft_correct_input(char **av)
{
	int	i;
	int	n_zeros;

	i = 1;
	while (av[i])
	{
		if (!ft_is_num(av[i]))
			return (0);
		n_zeros += ft_is_zero(av[i]);
		i++;
	}
	if (n_zeros < 0)
		return (0);
	if (ft_n_duplicate(av))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	int		*tab;
	char	**dig;

	i = 0;
	j = 0;
	ft_printf("\n%d\n", ac);
	if (ac > 2)
	{
	}
	else if (ac == 2)
	{
	}
	ft_printf("\nError55555\n");
}
