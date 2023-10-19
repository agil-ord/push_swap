#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"

# define INT_MAX +2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				data;
	int				pos;
	int				end_pos;
	int				len;
	int				target_a;
	int				moves_a;
	int				moves_b;
	int				moves_total;
	int				flag_reverse;
	int				flag_rotate;
	struct s_stack	*next;
}	t_stack;

typedef struct s_node
{
	int				data;
	int				pos;
	int				end_pos;
	int				len;
}	t_node;

int		ft_read_args(t_stack **stack, int ac, char **av);
int		ft_args_numbers(t_stack **stack, int ac, char **av);
int		ft_args_string(t_stack **stack, int ac, char **av);
int		ft_max_min(long nb);
int		ft_is_sorted(t_stack *lst);
int		ft_stack_is_empty(t_stack *stack);
void	ft_sort_stack_bubble(t_stack *stack);
void	ft_newNode(t_stack **stack, int data, int end_pos);:w
void	ft_push(t_stack **stack_1, t_stack **stack_2, char name_stack,
			int print);
//sa y sb : Intercambia los dos primeros elementos del stack a o b. 
//No hace nada si hay uno o menos elementos
void	ft_s(t_stack **stack, char name_stack, int print);
//swap a y b a la vez
void	ft_s_both(t_stack **stack_1, t_stack **stack_2, int print);
//ra o rb rotate a o b: Desplaza hacia arriba todos los elementos del stack 
//a una posición,de forma que el primer elemento se convierte en el último
int		ft_r(t_stack **lst, char name_stack, int print);
//rr: rotate a y b a la vez
void	ft_r_both(t_stack **stack_1, t_stack **stack_2, int print);
//rra o rrb reverse rotate a o b: Desplaza hacia abajo todos los elementos del 
//stack a una posición, de forma que el último elemento se convierte en el
//primero
void	ft_rev_r(t_stack **lst, char number_stack, int print);
// reverse rotate los dos a la vez
void	ft_rev_r_both(t_stack **stack_1, t_stack **stack_2, int print);

void	ft_free_stack(t_stack **lst);
void	ft_free_array(char **array);
t_stack	*ft_last_node(t_stack **lst);
void	ft_del_last_node(t_stack **lst);
void	ft_del_last_node2(t_stack **lst);
void	ft_lst_del_node(t_stack *lst);
t_stack	*ft_before_last_node(t_stack *lst);
t_stack	*ft_copy_stack(t_stack *stack1);
int		ft_find_data_in_stack(int find, t_stack *stack);
void	ft_read_node(t_stack *stack, t_node *node);
void	ft_minus(t_stack *tmp);
void	ft_update_index(t_stack *stack, t_stack *stack_sorted);
void	ft_sort_full(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_three(t_stack **stack_a);
void	ft_calc_target(t_stack *stack_b, t_stack *stack_a);
void	ft_calc_near(t_stack *stack_b, int len);
void	ft_calc_moves(t_stack *stack_b, t_stack	*temp, int len);
void	ft_calc_choose(t_stack	*temp);
int		ft_find_endpos_in_stack(int ind, t_stack *stack);
void	ft_move(t_stack **stack_a, t_stack **stack_b);
void	ft_move2(t_stack *temp, t_stack **stack_a, t_stack **stack_b);
int		ft_min_endpos(t_stack *stack_a);
int		ft_max_endpos(t_stack *stack_a);
void	ft_r_iter(t_stack **lst, char name_stack, int print, int iter);
void	ft_rev_r_iter(t_stack **lst, char name_stack, int print,
			int iter);
void	ft_rev_r_both_iter(t_stack **stack_1, t_stack **stack_2,
			int print, int iter);
void	ft_rev_r_and_s(t_stack **stack_a, char c, int print);
void	ft_r_and_s(t_stack **stack_a, char c, int print);
int		ft_first_end_pos(t_stack *stack_a);
int		ft_second_end_pos(t_stack *stack_a);
int		ft_third_end_pos(t_stack *stack_a);
int		ft_small_second_end_pos(t_stack *stack_a);
void	ft_leaks(void);
void	ft_initnode(t_stack **new, int data, int end_pos, int len);
int		ft_read_lines(t_stack **stack_a, t_stack **stack_b);
int		ft_read_lines_2(t_stack **stack_a, t_stack **stack_b, char *line);
long	ft_atol(const char *str);
int		ft_check_input(char *str);
void	ft_exec_move(t_stack **stack_a, t_stack **stack_b);

#endif
