/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:31:01 by agil-ord          #+#    #+#             */
/*   Updated: 2023/10/18 20:00:29 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	ft_initnode(t_stack **new, int data, int end_pos, int len)
{
	(*new) = (t_stack *)malloc(sizeof(t_stack));
	if (!(*new))
		return ;
	(*new)->data = data;
	(*new)->end_pos = end_pos;
	(*new)->len = len;
	(*new)->moves_a = 0;
	(*new)->moves_b = 0;
	(*new)->target_a = 0;
	(*new)->moves_total = 0;
	(*new)->flag_rotate = 0;
	(*new)->flag_reverse = 0;
	(*new)->next = NULL;
}

void	ft_newNode(t_stack **stack, int data, int end_pos)
{
	t_stack			*new;
	t_stack			*aux;
	unsigned int	i;

	i = 1;
	ft_initnode(&new, data, end_pos, 0);
	if (*stack == NULL)
	{
		(*stack) = new;
		(*stack)->len = 1;
		(*stack)->pos = i;
	}
	else
	{
		i++;
		aux = *stack;
		aux->len++;
		while (aux->next != NULL)
		{
			i++;
			aux = aux->next;
		}
		new->pos = i;
		aux->next = new;
	}
}

static int	ft_is_tab(char 	c)
{
	int	flag;

	flag = 0;
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v')
		flag = 1;
	if (flag == 0 && (c == '\f' || c == '\r'))
		flag = 1;
	return (flag);
}

long	ft_atol(const char *str)
{
	long	result;
	int		i;
	long	flag;

	result = 0;
	i = 0;
	flag = 1;
	while (ft_is_tab(str[i]))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (result * flag);
}

int	ft_check_input(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	if (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] != '\0')
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}
