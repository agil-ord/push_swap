#include "push_swap.h"


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
//ss funciona
void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}