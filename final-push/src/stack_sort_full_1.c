/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_full_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:37:46 by agil-ord          #+#    #+#             */
/*   Updated: 2023/10/19 13:48:33 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_full(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack_sorted;
	int		round;

	stack_sorted = ft_copy_stack(*stack_a);
	ft_sort_stack_bubble(stack_sorted);
	ft_update_index(*stack_a, stack_sorted);
	round = (*stack_a)->len;
	while ((*stack_a)->len > 3)
	{
		if ((--round > 3)
			&& ft_last_node(stack_a)->end_pos < ((*stack_a)->len / 2))
			ft_r(stack_a, 'a', 1);
		else
			ft_push(stack_a, stack_b, 'b', 1);
	}
	ft_sort_three(stack_a);
	ft_update_index(*stack_a, stack_sorted);
	while ((*stack_b) && (*stack_b)->len > 0)
		ft_exec_move(stack_a, stack_b);
	if (((*stack_a)->end_pos - (*stack_a)->pos > 0))
		ft_r_iter(stack_a, 'a', 1, (*stack_a)->end_pos - (*stack_a)->pos);
	else
		ft_rev_r_iter(stack_a, 'a', 1,
			(*stack_a)->end_pos - (*stack_a)->pos);
	ft_free_stack(&stack_sorted);
}

void	ft_exec_move(t_stack **stack_a, t_stack **stack_b)
{
	ft_calc_target(*stack_b, *stack_a);
	ft_calc_near(*stack_b, (*stack_a)->len);
	ft_move(stack_a, stack_b);
}

void	ft_calc_target(t_stack *stack_b, t_stack *stack_a)
{
	t_stack	*aux;

	aux = stack_b;
	while (aux)
	{
		aux->target_a = ft_find_endpos_in_stack(aux->end_pos, stack_a);
		aux = aux->next;
	}
}

void	ft_calc_moves(t_stack	*stack_b, t_stack	*aux, int len)
{
	if (aux->pos > stack_b->len / 2)
		aux->moves_b = stack_b->len - aux->pos;
	else
		aux->moves_b = aux->pos * -1;
	if (aux->target_a > len / 2)
		aux->moves_a = len - aux->target_a + 1;
	else
		aux->moves_a = aux->target_a * -1 + 1;
	aux->flag_rotate = 0;
	aux->flag_reverse = 0;
}

void	ft_calc_choose(t_stack	*aux)
{
	int		any_choose;

	any_choose = 0;
	if (aux->moves_a < 0)
	{
		any_choose = aux->moves_a * -1;
		aux->flag_reverse++;
	}
	else
	{
		aux->flag_rotate++;
		any_choose = aux->moves_a;
	}
	if (aux->moves_b < 0)
	{
		any_choose += (aux->moves_b * -1);
		aux->flag_reverse++;
	}
	else
	{
		aux->flag_rotate++;
		any_choose += aux->moves_b;
	}
	aux->moves_total = any_choose;
}
