#include "push_swap.h"

//intercambia los dos primeros elementos encima del stack a. No hace nada si hay uno o menos elementos.

void	ft_sa(t_stack **stack_a)
{
	t_stack	*aux;

	if (*stack_a && (*stack_a)->next)
	{
		aux = (*stack_a)->next; //guardo el segundo elemento
		(*stack_a)->next = aux->next; //el primer elemento apunta al tercero
		aux->next = *stack_a; //el segundo elemento apunta al primero
		*stack_a = aux; 	//el segundo elemento pasa a ser el primero
		//aqui despues tendria que estar liberando la memoria de aux y stack_a
	}
}

//intercambia los dos primeros elementos encima del stack b. No hace nada si hay uno o menos elementos

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

//ft_sa y ft_sb al mismo tiempo llamado ss

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}

//toma el primer elemento en la parte superior de b y lo pone en la parte superior de a. No hace nada si b está vacío. Se llamara pa

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	if (*stack_b)
	{
		aux = *stack_b; //guardo el primer elemento de b
		*stack_b = (*stack_b)->next; //b pasa a ser el segundo elemento
		aux->next = *stack_a; //el primer elemento de b apunta al primer elemento de a
		*stack_a = aux; //el primer elemento de a pasa a ser el primer elemento de b
		//aqui despues tendria que estar liberando la memoria de aux y stack_b
	}
}


//toma el primer elemento en la parte superior de a y lo pone en la parte superior de b. No hace nada si a está vacío. Se llamara pb

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	if (*stack_a)
	{
		aux = *stack_a; //guardo el primer elemento de a
		*stack_a = (*stack_a)->next; //a pasa a ser el segundo elemento
		aux->next = *stack_b; //el primer elemento de a apunta al primer elemento de b
		*stack_b = aux; //el primer elemento de b pasa a ser el primer elemento de a
		//aqui despues tendria que estar liberando la memoria de aux y stack_a
	}
}


//desplaza hacia arriba todos los elementos del stack a una posición, de forma que el primer elemento se convierte en el último.

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

//desplaza hacia arriba todos los elementos del stack b una posición, de forma que el primer elemento se convierte en el último.

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

//ft_ra y ft_rb al mismo tiempo llamado rr

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}

//desplaza hacia abajo todos los elementos del stack a una posición, de forma que el último elemento se convierte en el primero.

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

//desplaza hacia abajo todos los elementos del stack b una posición, de forma que el último elemento se convierte en el primero.

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


//ft_rra y ft_rrb al mismo tiempo llamado rrr

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
}

