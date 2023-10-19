/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_full_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:38:13 by agil-ord          #+#    #+#             */
/*   Updated: 2023/10/19 13:49:39 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_first_end_pos(t_stack *stack_a)
{
	if (stack_a->end_pos < stack_a->next->end_pos
		&& stack_a->end_pos < stack_a->next->next->end_pos)
		return (1);
	else
		return (0);
}

int	ft_second_end_pos(t_stack *stack_a)
{
	if ((stack_a->end_pos > stack_a->next->end_pos
			&& stack_a->end_pos < stack_a->next->next->end_pos)
		|| (stack_a->end_pos < stack_a->next->end_pos
			&& stack_a->end_pos > stack_a->next->next->end_pos))
		return (1);
	else
		return (0);
}

int	ft_third_end_pos(t_stack *stack_a)
{
	if (stack_a->end_pos > stack_a->next->end_pos
		&& stack_a->end_pos > stack_a->next->next->end_pos)
		return (1);
	else
		return (0);
}

int	ft_small_second_end_pos(t_stack *stack_a)
{
	if (stack_a->next->end_pos < stack_a->next->next->end_pos)
		return (1);
	else
		return (0);
}

void	ft_sort_three(t_stack **stack_a)
{
	if (ft_is_sorted(*stack_a))
		return ;
	if (ft_first_end_pos(*stack_a))
		ft_s(stack_a, 'a', 1);
	else if (ft_second_end_pos(*stack_a))
		if (ft_small_second_end_pos(*stack_a))
			ft_rev_r_and_s(stack_a, 'a', 1);
	else
		ft_r(stack_a, 'a', 1);
	else if (ft_third_end_pos(*stack_a))
	{
		if (ft_small_second_end_pos(*stack_a))
			ft_rev_r(stack_a, 'a', 1);
		else
			ft_r_and_s(stack_a, 'a', 1);
	}
}
