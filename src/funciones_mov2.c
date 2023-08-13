#include "push_swap.h"

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

//rb funciona
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

//rr funciona
void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}

//rra funciona
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

//rrb funciona
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