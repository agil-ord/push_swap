/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:25:44 by agil-ord          #+#    #+#             */
/*   Updated: 2023/07/31 12:28:27 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct s_stack
{
	int				value;//valor : el entero que debemos ordenar,
	int				index;//index : su índice en la lista de todos los valores que deben ordenarse,
	int				pos;//pos : su posición actual en su pila,
	int				tar_pos; //para elementos en la pila B, la posición de destino en la pila A donde debería estar,
	int				cost_a;//cuántas acciones costaría rotar la pila A para que el elemento en la posición de destino llegue a la parte superior de la pila A,
	int				cost_b;//cuántas acciones costaría rotar la pila B para que este elemento llegue a la parte superior de la pila B,
	struct s_stack	*next;//puntero al siguiente elemento de la lista.
}				t_stack;


int		ft_c_duplicate(char **s);
int		ft_cmp_str(const char *s1, const char *s2);
int		ft_is_zero(char *s);
int		ft_is_num(char *s);
int		ft_sign(char c);
long	ft_atol_push(const char *str);
int		ft_isspace(char c);
int		ft_correct_input(char **cadena);
int		ft_n_duplicate(int *s, int size);
// t_stack stack_a;
// t_stack stack_b;

#endif

