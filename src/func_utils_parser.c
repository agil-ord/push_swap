/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_utils_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:48:35 by agil-ord          #+#    #+#             */
/*   Updated: 2023/08/13 17:48:50 by agil-ord         ###   ########.fr       */
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
	//if (result > 2147483647 || result < -2147483648)
	//	return (ft_printf("Error min o max entero"), 0);
	return (result * flag);
}

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