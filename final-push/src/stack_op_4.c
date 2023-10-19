/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:36:53 by agil-ord          #+#    #+#             */
/*   Updated: 2023/10/19 13:47:51 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack_bubble(t_stack *stack)
{
	int		swapped;
	int		swap;
	t_stack	*cur;

	cur = stack;
	swapped = 1;
	while (swapped == 1)
	{
		swapped = 0;
		while (cur != 0 && cur->next != 0)
		{
			if (cur->data < cur->next->data)
			{
				swap = cur->data;
				cur->data = cur->next->data;
				cur->next->data = swap;
				swapped = 1;
			}
			cur = cur->next;
		}
		cur = stack;
	}
}

t_stack	*ft_copy_stack(t_stack *stack1)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = stack1;
	temp2 = NULL;
	while (temp)
	{
		ft_newNode(&temp2, temp->data, 0);
		temp = temp->next;
	}
	ft_free_stack(&temp);
	return (temp2);
}

int	ft_find_data_in_stack(int find, t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		if (find == temp->data)
			return (temp->pos);
		temp = temp->next;
	}
	return (0);
}

void	ft_update_index(t_stack *stack, t_stack *stack_sorted)
{
	t_stack	*temp;
	int		pos;

	temp = stack;
	while (temp)
	{
		pos = ft_find_data_in_stack(temp->data, stack_sorted);
		if (pos != -1)
			temp->end_pos = pos;
		temp = temp->next;
	}
}
