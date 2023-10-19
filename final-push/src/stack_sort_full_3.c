/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_full_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:58:36 by agil-ord          #+#    #+#             */
/*   Updated: 2023/10/19 13:49:43 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_calc_near(t_stack *stack_b, int len)
{
	t_stack	*aux;

	aux = stack_b;
	while (aux)
	{
		ft_calc_moves(stack_b, aux, len);
		ft_calc_choose(aux);
		aux = aux->next;
	}
}

int	ft_min_endpos(t_stack *stack_a)
{
	t_stack	*aux;
	int		min;
	int		minpos;

	aux = stack_a;
	min = aux->end_pos;
	minpos = aux->pos;
	while (aux)
	{
		if (aux->end_pos < min)
		{
			minpos = aux->pos;
			min = aux->end_pos;
		}
		aux = aux->next;
	}
	return (minpos);
}

int	ft_find_endpos_in_stack(int ind, t_stack *stack_a)
{
	t_stack	*aux;
	int		pos;
	int		minmax;

	pos = 1;
	aux = stack_a;
	minmax = 9999;
	pos = ft_min_endpos(stack_a);
	while (aux)
	{
		if (ind < aux->end_pos)
		{
			if (aux->end_pos < minmax)
			{
				pos = aux->pos;
				minmax = aux->end_pos;
			}
		}
		aux = aux->next;
	}
	return (pos);
}

void	ft_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;
	int		choose;
	int		pos_b_to_move;
	int		done;

	choose = 0;
	done = 0;
	aux = *stack_b;
	while (aux)
	{
		if (aux->moves_total < choose || choose == 0)
		{
			choose = aux->moves_total;
			pos_b_to_move = aux->pos;
		}
		aux = aux->next;
	}
	aux = *stack_b;
	while (aux)
	{
		if (aux->pos == pos_b_to_move && !done++)
			ft_move2(aux, stack_a, stack_b);
		aux = aux->next;
	}
	ft_push(stack_b, stack_a, 'a', 1);
}

void	ft_move2(t_stack *aux, t_stack **stack_a, t_stack **stack_b)
{
	if (aux->moves_a < 0)
		ft_rev_r_iter(stack_a, 'a', 1, aux->moves_a * -1);
	else
		ft_r_iter(stack_a, 'a', 1, aux->moves_a);
	if (aux->moves_b < 0)
		ft_rev_r_iter(stack_b, 'b', 1, aux->moves_b * -1);
	else
		ft_r_iter(stack_b, 'b', 1, aux->moves_b);
}
