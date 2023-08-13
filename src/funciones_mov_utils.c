#include "push_swap.h"

int	ft_lstsize_push(t_stack *stack_a)
{
	int	count;
	t_stack	*tmp;

	tmp = stack_a;
	count = 0;
	if (!tmp)
		return (0);
	while (tmp -> next != 0)
	{
		tmp = tmp -> next;
		count++;
	}
	if (tmp -> next == 0)
		count++;
	return (count);
}

void push(t_stack **stack, int value)
{
	t_stack *new_node;

	new_node = (t_stack*)malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
		printf("Error: No se pudo asignar memoria para el nuevo nodo.\n");
		return ;
	}
	new_node->content = value;
	new_node->index = 0;
	new_node->next = *stack;
	*stack = new_node;
}

void print_stack(t_stack *stack)
{
	t_stack *current;
	current = stack;
	while (current != NULL)
	{
		printf("Valor: %d | Índice: %d\n", current->content, current->index);
		current = current->next;
	}
	printf("\n");
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
}

void ft_index(t_stack *stack_a)//indices correctamente asignados
{
	int idx;
	int len;
	t_stack *head; // Cabeza de la lista
	t_stack *aux; // Nodo que comprobará el menor posible

	head = stack_a;
	idx = 1;
	len = ft_lstsize_push(stack_a);
	aux = stack_a;
	while(len > 0)
	{
		stack_a = head;
		while(stack_a != NULL && stack_a->index != 0)
			stack_a = stack_a->next;
		aux = stack_a;
		while(stack_a != NULL)
		{	
			if (aux->content > stack_a->content && stack_a->index == 0)
				aux = stack_a;
			stack_a = stack_a->next;
		}
		aux->index = idx;
		idx++;
		len--;
	}
}

