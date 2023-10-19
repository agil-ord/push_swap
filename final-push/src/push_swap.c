/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:31:52 by agil-ord          #+#    #+#             */
/*   Updated: 2023/10/19 13:46:17 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	ft_leaks(void)
{
	system("leaks -q push_swap");
}
*/
void	push_swap(int ac, char **av)
{
	(void) av;
	if (ac == 1)
		return ;
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*stack_sorted;
	int		flag;

	flag = 0;
	if (ac == 1)
		return (0);
	flag = ft_read_args(&stack_a, ac, av);
	if (flag)
		return (flag);
	if (stack_a->len == 2)
		if (stack_a->data < stack_a->next->data)
			ft_s(&stack_a, 'a', 1);
	if (stack_a->len == 1)
		return (0);
	if (ft_is_sorted(stack_a) || stack_a->len < 3)
		return (0);
	stack_sorted = ft_copy_stack(stack_a);
	ft_sort_stack_bubble(stack_sorted);
	ft_update_index(stack_a, stack_sorted);
	ft_sort_full(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (ft_free_stack(&stack_sorted), 0);
}
