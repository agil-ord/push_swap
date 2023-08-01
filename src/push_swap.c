/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:23:19 by agil-ord          #+#    #+#             */
/*   Updated: 2023/07/31 12:28:01 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
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

