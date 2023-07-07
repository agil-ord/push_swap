/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:25:44 by agil-ord          #+#    #+#             */
/*   Updated: 2023/07/01 17:03:38 by agil-ord         ###   ########.fr       */
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

// t_stack stack_a;
// t_stack stack_b;

#endif