/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:25:44 by agil-ord          #+#    #+#             */
/*   Updated: 2023/08/13 17:53:31 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"

# define INT_MAX +2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				content;//valor : el entero que debemos ordenar,
	int				index;//index : su índice en la lista de todos los valores que deben ordenarse,
	//int				pos;//pos : su posición actual en su pila,
	//int				tar_pos; //para elementos en la pila B, la posición de destino en la pila A donde debería estar,
	//int				cost_a;//cuántas acciones costaría rotar la pila A para que el elemento en la posición de destino llegue a la parte superior de la pila A,
	//int				cost_b;//cuántas acciones costaría rotar la pila B para que este elemento llegue a la parte superior de la pila B,
	struct s_stack	*next;//puntero al siguiente elemento de la lista.
}				t_stack;

//funciones comprobacion
int		ft_c_duplicate(char **s);
int		ft_cmp_str(const char *s1, const char *s2);
int		ft_is_zero(char *s);
int		ft_is_num(char *s);
int		ft_sign(char c);
long	ft_atol_push(const char *str);
int		ft_isspace(char c);
int		ft_n_duplicate(int *s, int size);


//main
int		ft_correct_input(char **cadena);
char 	**create_stack_other(int ac, char **av);
int 	process_input_and_push(int *array_stack_a, t_stack **stack_a, char **array_stack_other);
int		main(int ac, char **av);
//funciones de movimento
void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);



//funcion asignar indices
void ft_index(t_stack *stack_a);
//sacar num total pila
int	ft_lstsize_push(t_stack *stack_a);
//ir mirando que pasa en la pila
void print_stack(t_stack *stack);
//introducr los valores a la pila
void push(t_stack **stack, int value);
//divisions main



#endif

