/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mov_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:32:38 by agil-ord          #+#    #+#             */
/*   Updated: 2023/10/19 19:09:13 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	ft_s(t_stack **stack, char name_stack, int print)
{
	t_stack	*tmp;
	int		tmp_data;

	if (!(*stack) || (*stack)->len < 2)
	{
		if (print)
			ft_printf("s%c\n", name_stack);
		return ;
	}
	tmp = (*stack);
	while (tmp->next->next)
	{
		tmp_data = tmp->data;
		tmp = tmp->next;
	}
	tmp_data = tmp->data;
	tmp->data = tmp->next->data;
	tmp->next->data = tmp_data;
	if (print)
		ft_printf("s%c\n", name_stack);
	return ;
}

void	ft_s_both(t_stack **stack_1, t_stack **stack_2, int print)
{
	ft_s(stack_1, 'a', 0);
	ft_s(stack_2, 'b', 0);
	if (print)
		ft_printf("ss\n");
	return ;
}

void	ft_push(t_stack **stack_1, t_stack **stack_2,
			char name_stack, int print)
{
	int		tmp_data;
	int		tmp_endpos;

	if (!(*stack_1) || (*stack_1)->len < 1)
	{
		if (print)
			ft_printf("p%c\n", name_stack);
		return ;
	}
	tmp_data = ft_last_node(&(*stack_1))->data;
	tmp_endpos = ft_last_node(&(*stack_1))->end_pos;
	ft_del_last_node(stack_1);
	ft_newNode(stack_2, tmp_data, tmp_endpos);
	if (print)
		ft_printf("p%c\n", name_stack);
	return ;
}

int	ft_r(t_stack **stack, char name_stack, int print)
{
	t_stack	*tmp;
	t_stack	*new;

	if (ft_stack_is_empty(*stack) || !(*stack) || !((*stack)->next))
		if (print)
			return (write(1, "r", 1), write(1, &name_stack, 1),
				write(1, "\n", 1));
	tmp = *stack;
	while (tmp->next)
	{
		tmp->pos++;
		tmp = tmp->next;
	}
	ft_initnode(&new, tmp->data, tmp->end_pos, (*stack)->len);
	ft_del_last_node(stack);
	(*stack)->len = 0;
	new->pos = 1;
	new->next = *stack;
	*stack = new;
	if (print)
		ft_printf("r%c\n", name_stack);
	return (0);
}

void	ft_rotate_both(t_stack **stack_1, t_stack **stack_2, int print)
{
	ft_r(stack_1, 'a', 0);
	ft_r(stack_2, 'b', 0);
	if (print)
		ft_printf("rr");
	return ;
}
