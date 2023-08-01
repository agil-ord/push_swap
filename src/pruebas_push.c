#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int content;
	struct s_stack *next;
} t_stack;

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
	new_node->next = *stack;
	*stack = new_node;
}

void print_stack(t_stack *stack)
{
	t_stack *current;
	current = stack;
	while (current != NULL)
	{
		printf("%d ", current->content);
		current = current->next;
	}
	printf("\n");
}

//sa funciona
void ft_sa(t_stack **stack_a)
{
	t_stack *aux;

	if (*stack_a && (*stack_a)->next)
	{
		aux = (*stack_a)->next; //guardo el segundo elemento
		(*stack_a)->next = aux->next; //el primer elemento apunta al tercero
		aux->next = *stack_a; //el segundo elemento apunta al primero
		*stack_a = aux; //el segundo elemento pasa a ser el primero
		//aqui despues tendria que estar liberando la memoria de aux y stack_a
	}
}
//sb funciona
void	ft_sb(t_stack **stack_b)
{
	t_stack	*aux;

	if (*stack_b && (*stack_b)->next)
	{
		aux = (*stack_b)->next; //guardo el segundo elemento
		(*stack_b)->next = aux->next; //el primer elemento apunta al tercero
		aux->next = *stack_b; //el segundo elemento apunta al primero
		*stack_b = aux; 	//el segundo elemento pasa a ser el primero
		//aqui despues tendria que estar liberando la memoria de aux y stack_b
	}
}



//pa funciona
void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	if (*stack_b)
	{
		aux = *stack_b; //guardo el primer elemento de b
		*stack_b = (*stack_b)->next; //b pasa a ser el segundo elemento
		aux->next = *stack_a; //el primer elemento de b apunta al primer elemento de a
		*stack_a = aux; //el primer elemento de a pasa a ser el primer elemento de b
	
}
//pb funciona
void	ft_pb(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*aux;

	if (*stack_a)
	{
		aux = *stack_a; //guardo el primer elemento de a
		*stack_a = (*stack_a)->next; //a pasa a ser el segundo elemento
		aux->next = *stack_b; //el primer elemento de a apunta al primer elemento de b
		*stack_b = aux; //el primer elemento de b pasa a ser el primer elemento de a
		//No se si tengo que hacerlo hasta llegar el ultimo elemento de a o solo con el primero cambiando la direccion de donde apunte
		//es posible que si quiero meterle indices tenga que hacerlo hasta el ultimo elemento
		//aqui despues tendria que estar liberando la memoria de aux y stack_a
	}
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}

void	ft_ra(t_stack **stack_a)
{
	t_stack	*aux;
	t_stack	*aux2;

	if (*stack_a && (*stack_a)->next)
	{
		aux = *stack_a; //guardo el primer elemento de a
		*stack_a = (*stack_a)->next; //a pasa a ser el segundo elemento
		aux2 = *stack_a; //guardo el segundo elemento de a
		while (aux2->next) //recorro hasta el ultimo elemento de a
			aux2 = aux2->next;
		aux2->next = aux; //el ultimo elemento de a apunta al primer elemento de a
		aux->next = NULL; //el primer elemento de a apunta a null
		//aqui despues tendria que estar liberando la memoria de aux y stack_a
	}
}

void	ft_rb(t_stack **stack_b)
{
	t_stack	*aux;
	t_stack	*aux2;

	if (*stack_b && (*stack_b)->next)
	{
		aux = *stack_b; //guardo el primer elemento de b
		*stack_b = (*stack_b)->next; //b pasa a ser el segundo elemento
		aux2 = *stack_b; //guardo el segundo elemento de b
		while (aux2->next) //recorro hasta el ultimo elemento de b
			aux2 = aux2->next;
		aux2->next = aux; //el ultimo elemento de b apunta al primer elemento de b
		aux->next = NULL; //el primer elemento de b apunta a null
		//aqui despues tendria que estar liberando la memoria de aux y stack_b
	}
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}

void	ft_rra(t_stack **stack_a)
{
	t_stack	*aux;
	t_stack	*aux2;

	if (*stack_a && (*stack_a)->next)
	{
		aux = *stack_a; //guardo el primer elemento de a
		while (aux->next->next) //recorro hasta el penultimo elemento de a
			aux = aux->next;
		aux2 = aux->next; //guardo el ultimo elemento de a
		aux->next = NULL; //el penultimo elemento de a apunta a null
		aux2->next = *stack_a; //el ultimo elemento de a apunta al primer elemento de a
		*stack_a = aux2; //el ultimo elemento de a pasa a ser el primer elemento de a
		//aqui despues tendria que estar liberando la memoria de aux y stack_a
	}
}

void	ft_rrb(t_stack **stack_b)
{
	t_stack	*aux;
	t_stack	*aux2;

	if (*stack_b && (*stack_b)->next)
	{
		aux = *stack_b; //guardo el primer elemento de b
		while (aux->next->next) //recorro hasta el penultimo elemento de b
			aux = aux->next;
		aux2 = aux->next; //guardo el ultimo elemento de b
		aux->next = NULL; //el penultimo elemento de b apunta a null
		aux2->next = *stack_b; //el ultimo elemento de b apunta al primer elemento de b
		*stack_b = aux2; //el ultimo elemento de b pasa a ser el primer elemento de b
		//aqui despues tendria que estar liberando la memoria de aux y stack_b
	}
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
}


int	main()
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;

	push(&stack_a, 9);
	push(&stack_a, 3);
	push(&stack_a, 2);
	push(&stack_a, 1);
	push(&stack_b, 6);
	push(&stack_b, 5);
	push(&stack_b, 7);
	push(&stack_b, 63);
	printf("\n");
	printf("Pila antes de aplicar funcion a a: ");
	print_stack(stack_a);
	printf("Pila antes de aplicar funcion a b: ");
	print_stack(stack_b);
	printf("\n\n");
	//ft_ss(&stack_a, &stack_b);
	//ft_sa(&stack_a);
	//ft_sb(&stack_b);
	//ft_ss(&stack_a, &stack_b);
	//ft_pb(&stack_b, &stack_a);
	//ft_pb(&stack_b, &stack_a);
	//ft_pa(&stack_a, &stack_b);
	//ft_ra(&stack_a);
	//ft_rb(&stack_b);
	//ft_rr(&stack_a, &stack_b);
	//ft_rra(&stack_a);
	//ft_rrb(&stack_b);
	//ft_rrr(&stack_a, &stack_b);
	printf("Pila después de aplicar ft a: ");
	print_stack(stack_a);
	printf("Pila después de aplicar ft b: ");
	print_stack(stack_b);
	printf("\n");
	while (stack_a != NULL)
	{
		t_stack *temp = stack_a;
		stack_a = stack_a->next;
		free(temp);
	}
	return 0;
}