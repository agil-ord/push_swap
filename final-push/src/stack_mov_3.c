/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mov_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:34:09 by agil-ord          #+#    #+#             */
/*   Updated: 2023/10/15 20:34:32 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void	ft_rev_r_and_s(t_stack **stack_a, char c, int print)
{
	ft_rev_r(stack_a, c, print);
	ft_s(stack_a, c, print);
}

void	ft_r_and_s(t_stack **stack_a, char c, int print)
{
	ft_r(stack_a, c, print);
	ft_s(stack_a, c, print);
}

void	ft_read_node(t_stack *stack, t_node *node)
{
	(*node).len = stack->len;
	(*node).data = stack->data;
	(*node).end_pos = stack->end_pos;
}

void	ft_minus(t_stack *tmp)
{
	tmp->pos--;
	tmp->len = 0;
}
