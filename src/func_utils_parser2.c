/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_utils_parser2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:23:19 by agil-ord          #+#    #+#             */
/*   Updated: 2023/08/13 17:49:33 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
int	ft_c_duplicate(char **s)
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

int ft_n_duplicate(int *s, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{	
		j = i + 1;
		while (j < size)
		{
			if (j != i && s[i] == s[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

