#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int content; //valor del nodo
	struct s_stack *next; //puntero al siguiente nodo
	int index; //índice en la lista de todos los valores que deben ordenarse
	int pos; //posición en la pila
	int target_pos; //para los elementos de la pila B, la posición de destino en la pila A donde debería estar
} t_stack;





/*
a ver la funcion recibiria
t_stack stack_a

loque va devolviendo es cada uno de los valores de la pila con un indice, vamos a intertarlo con arrays.
tengo que hacer un bucle e ir comparando dos a dos hasta encontrar el minimo
int idx;
t_stack aux;
idx = 1;


while(t_stack->index == 0 || t_stack->next != NULL)
{
	if (t_stack->value < t_stack->next->value && t_stack->index == 0)
	{
		aux->content = stack_a->content;
		t_stack->next;
	}
	

}
t_stack->index = idx;
idx++;
*/


//compruebo si me queda algun valor de indice sin asignar
void is_0_ind_stack(t_stack *stack)
{
	t_stack *current = stack;
	while (current != NULL)
	{
		if(current->index == 0)
			return 1;
		current = current->next;		
	}
	return 0;
}
//una funcion que aigne un indice a cada nodo de la pila segun su valor de menor a mayor 
void min_ind(t_stack *stack)
{
	t_stack *stack_ord = stack;//para recorrer la pila
	t_stack *menor; 
	int i;

	i = 1;
	menor = NULL;
	while(is_0_ind_stack(stack_ord) == 1)
	{
		menor->value = stack_ord->value;
		while (aux != NULL)//aqui busco el menor
		{
			if (stack->value < menor->value && (is_0_ind_stack == 1))//aqui tengo que asignar el valor de index 
			{
				menor = a;// el menor valor y cullor //solo si aux tiene el menor valor
				return;
			}
			aux = aux->next;
		}
		i++;
	}
}

void push(t_stack **stack, int value)
{
	t_stack *new_node = (t_stack*)malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
		printf("Error: No se pudo asignar memoria para el nuevo nodo.\n");
		return;
	}

	new_node->content = value; // Asignamos el valor al nuevo nodo
	new_node->next = *stack; // El nuevo nodo apunta al primer elemento de la pila
	new_node->index = 0; // Inicializamos el índice como -1 para indicar que aún no está asignado
	*stack = new_node; // El nuevo nodo pasa a ser el primer elemento de la pila
}

void print_stack(t_stack *stack)
{
	t_stack *current = stack;
	while (current != NULL)
	{
		printf("Valor: %d | Índice: %d\n", current->content, current->index);
		current = current->next;
	}
}

int main()
{
	t_stack *stack_a = NULL; // Inicializamos la pila como vacía

	// Añadir tres valores a la pila
	push(&stack_a, 3);
	push(&stack_a, 2);
	push(&stack_a, 8);
	push(&stack_a, 1);
	push(&stack_a, -8);
	push(&stack_a, 0);

	// Asignar índices a los valores dentro de la pila A
	min_index(stack_a);

	// Imprimir los elementos de la pila con sus índices
	print_stack(stack_a);

	// Liberar la memoria de la pila
	while (stack_a != NULL)
	{
		t_stack *temp = stack_a;
		stack_a = stack_a->next;
		free(temp);
	}

	return 0;
}

static void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}
void min_index(t_stack *stack)
{
	if (stack == NULL)
		return;

	int min_value = stack->content;

	// Encontrar el valor mínimo en la pila
	t_stack *current = stack->next;
	while (current != NULL)
	{
		if (current->content < min_value)
			min_value = current->content;
		current = current->next;
	}

	// Asignar índices en orden inverso a partir del valor máximo
	//current->index = 1;
	current = stack;
	while (current != NULL)
	{
		current->index = min_value + 1;
		current = current->next;
	}
}


//una funcion que ordene la pila A de mayor a menos


int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

static int	get_target(t_stack **a, int b_idx, int target_idx, int target_pos) //b_idx es el indice del valor mas alto de la pila b
{
	t_stack	*tmp_a;

	tmp_a = *a; 
	while (tmp_a) 
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx) //si el indice de a es mayor que el indice de b y menor que el target 
		{
			target_idx = tmp_a->index; //asigno el indice de a a target
			target_pos = tmp_a->pos; //asigno la posicion de a a target
		}
		tmp_a = tmp_a->next; //avanzo en la pila a
	}
	if (target_idx != INT_MAX) //si el target es diferente de INT_MAX
		return (target_pos); //retorno la posicion del target
	tmp_a = *a; //si no, vuelvo a recorrer la pila a
	while (tmp_a) //recorro la pila a
	{
		if (tmp_a->index < target_idx) //si el indice de a es menor que el target
		{
			target_idx = tmp_a->index; //asigno el indice de a a target
			target_pos = tmp_a->pos; //asigno la posicion de a a target
		}
		tmp_a = tmp_a->next;  //avanzo en la pila a
	}
	return (target_pos);
}


void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b; //puntero a la pila b
	int		target_pos;	//posicion del target

	tmp_b = *b;
	get_position(a); //asigna la posicion a la pila a
	get_position(b); //asigna la posicion a la pila b
	target_pos = 0; //inicializa la posicion del target
	while (tmp_b) //recorre la pila b
	{
		target_pos = get_target(a, tmp_b->index, INT_MAX, target_pos); //asigna la posicion del target
		tmp_b->target_pos = target_pos;	//asigna la posicion del target a la pila b
		tmp_b = tmp_b->next; //avanza en la pila b
	}
}