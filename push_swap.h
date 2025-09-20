/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:24:40 by eunkim            #+#    #+#             */
/*   Updated: 2025/05/14 18:18:03 by eunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h> // check if this is needed for size_t

# define MERGE_SA_SB 1
# define MERGE_RA_RB 2
# define MERGE_RRA_RRB 3

typedef struct s_list
{
	int				value;
	size_t			index;
	size_t			cost;
	struct s_list	*next;
}					t_list;

typedef enum e_op
{
	invalid_op,
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_op;

typedef struct s_instr
{
	t_op			op;
	struct s_instr	*next;
}					t_instr;

char	**ft_split(char *str);
long	ft_atol(const char *str);

/* utils.c */
void	exit_error(void);
void	ft_freeall(char **s);
void	ft_freeall_and_exit(char **s);
void	free_stack(t_list *stack);
int		ft_strcmp(char *s1, char *s2);

/* manage_args.c */
int		*manage_args(char **str, long *size_out);

/* sort_arr.c */
void	bubble_sort(int *arr_sort, size_t size);
int		*sort_arr(int *arr, size_t size);
int		is_sorted_arr(int *arr, size_t size); // maybe not used anymore

/* operations: oper_swap.c, oper_push.c, oper_rotate.c, oper_rrotate.c */
void	do_sa(t_list **stack_a, t_instr **instr_list);
void	do_sb(t_list **stack_b, t_instr **instr_list);
void	do_ss(t_list **stack_a, t_list **stack_b, t_instr **instr_list);
void	do_pa(t_list **stack_b, t_list **stack_a, t_instr **instr_list);
void	do_pb(t_list **stack_a, t_list **stack_b, t_instr **instr_list);
void	do_ra(t_list **stack_a, t_instr **instr_list);
void	do_rb(t_list **stack_b, t_instr **instr_list);
void	do_rr(t_list **stack_a, t_list **stack_b, t_instr **instr_list);
void	do_rra(t_list **stack_a, t_instr **instr_list);
void	do_rrb(t_list **stack_b, t_instr **instr_list);
void	do_rrr(t_list **stack_a, t_list **stack_b, t_instr **instr_list);

/* ft_lst.c */
size_t	ft_lstsize(t_list *lst);
size_t	ft_lstmax(t_list *lst);
size_t	ft_lstmin(t_list *lst);
size_t	ft_lstmincost(t_list *lst);
t_list	*ft_lstnew(int value, size_t index);

/* stack.c */
t_list	*build_stack(int *int_arr, size_t size);
int		is_stack_sorted(t_list *stack);
int		is_stack_circularly_sorted(t_list *stack);
int		is_stack_inversely_sorted(t_list *stack);

/* sort_stack_utils.c */
size_t	get_min_loc(t_list *head);
size_t	get_node_loc(t_list *head, size_t node_val);
void	bring_min_to_top(t_list **stack_a, t_instr **instr);
void	mov_node_to_top(t_list **stk, char c, size_t val, t_instr **ins);

/* sort_small_stack.c */
void	sort_three(t_list **stack_a, t_instr **instr_list);
void	sort_small_stack(t_list **s_a, t_list **s_b, t_instr **inst, int size);
void	sort_small_medium_inversed_stack(t_list **stack_a);

/* sort_big_stack.c */
void	sort_big_stack(t_list **stk_a, int *int_arr, size_t size);

/* turk_sort.c */
void	turk_sort(t_list **stk_a, t_list **stk_b, t_instr **instr_list);

/* turk_sort_enhanced.c */
void	enhanced_turk(t_list **stk_a, t_list **stk_b, t_instr **instr_list);
void	enhanced_turk1(t_list **stk_a, t_list **stk_b, t_instr **instr_list);
void	enhanced_turk2(t_list **stk_a, t_list **stk_b, t_instr **instr_list);

/* turk_sort_utils.c - get closest lower or higher value */
size_t	get_closest_min(size_t idx_value, t_list *stack);
size_t	get_closest_max(size_t idx_value, t_list *stack);

/* turk_sort_utils.c - fill cost in stack a or b */
void	fillcost_a(t_list *a, t_list *b, size_t len_a, size_t len_b);
void	fillcost_b(t_list *b, t_list *a, size_t len_b, size_t len_a);

/* instr_utils.c */
size_t	instr_size(t_instr *instr);
void	add_instruction(t_instr **instr_list, t_op op);
void	print_instructions(t_instr *instr_list);
void	free_instructions(t_instr *instr_list);

/* instr_optimize.c */
void	offset_instructions(t_instr **instr_list);
void	merge_instructions(t_instr **instr_list);

#endif
