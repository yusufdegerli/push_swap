/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:48:15 by ydegerli          #+#    #+#             */
/*   Updated: 2023/03/10 12:27:37 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				last;
	int				first;
	struct s_stack	*next;
	struct s_stack	*before;
	int				index;
	int				stack_size;
}					t_stack;

void				ft_sa(t_stack **stack_a);
void				ft_sb(t_stack **stack_b);
void				ft_ss(t_stack **stack_a, t_stack **stack_b);
void				ft_pa(t_stack **stack_b, t_stack **stack_a);
void				ft_pb(t_stack **stack_a, t_stack **stack_b);
void				ft_ra(t_stack **stack_a);
void				ft_rb(t_stack **stack_b);
void				ft_rr(t_stack **stack_a, t_stack **stack_b);
void				ft_rra(t_stack **stack_a);
void				ft_rrb(t_stack **stack_b);
void				ft_rrr(t_stack **stack_a, t_stack **stack_b);
void				ft_sort_three(t_stack **stack_a);
void				ft_move_to_a(t_stack **stack_a, t_stack **stack_b);
void				ft_sort_five(t_stack **stack_a, t_stack **stack_b);
void				lis_helper_two(int *dst, int *prev, int *lis, int size);
void				ft_display_exit(void);

void				ft_stack_inverted(t_stack **stack_a);
void				ft_list_split(t_stack **stack_a, t_stack **stack_b,
						int size);
void				ft_stackadd_back(t_stack **lst, t_stack *new);
void				addlist(t_stack **stack_a, int ac, char **av);
void				ft_stackadd_front(t_stack **lst, t_stack *new);
void				ft_search_min(t_stack **stack_a, int size);
void				ft_stack_order(t_stack **stack_a);
void				ft_stackadd_back(t_stack **lst, t_stack *new);
void				ft_stackcheck(t_stack *stack_a, int check);
void				ft_stack_delete(t_stack **stack);
void				ft_write_lst(t_stack **stack_a, int argc, char **argv,
						int i);
void				ft_move_to_b(t_stack **stack_a, t_stack **stack_b, int *a,
						int mx);

int					lis_helper_three(int *lis, int size);
int					my_abs(int nb);
int					ft_strcmp(char *s1, char *s2);
int					ft_stacksize(t_stack *lst);
int					not_on_lis(t_stack *stack_a, int size_a, int *lis_ar,
						int lis_size);
int					ft_best_nbr_b(t_stack **s_b, int size_b, t_stack **s_a,
						int si_a);
int					ft_the_needed_b(int max, int size);
int					ft_the_needed_a(t_stack *stack_a, int cont, int size);
int					return_max_or_min(int cont, int *max_n_min, int size);
int					ft_max_or_min(t_stack *stack_a, int cont, int size);
int					ft_best_comb_helper(int *arr_a, int *arr_b, int *tmp,
						int size);
int					ft_max_nbr(int a, int b);
int					ft_best_comb(int *arr_a, int *arr_b, int size);
int					ft_best_nbr_b(t_stack **s_b, int size_b, t_stack **s_a,
						int si_a);
int					ft_move_a(int a, int b, t_stack **stack_a,
						t_stack **stack_b);

int					*lis_helper(int *lis, int size);
int					*lis_helper_one(int *prev, int size);
int					*lis(int *dst, int size, int *len);
int					*ft_copy_cont(t_stack *stack_a, int size);
int					*ft_intcpy(int *src, int n);

t_stack				*ft_stacknew(long int content);

void				ft_exec_sort(t_stack **stack_a, t_stack **stack_b,
						char *str);
void				ft_rrr_or_death(t_stack **stack_a, t_stack **stack_b,
						char *str);
void				ft_check_write_lst(t_stack **stack_a, int argc, char **argv,
						int i);
void				ft_check_lst_inverted(t_stack **stack_a);
void				ft_check_sort(t_stack *stack_a);
void				ft_check_argv_c(int argc, char **argv, t_stack **stack_a);
void				ft_check_argv(int argc, char **argv, t_stack **stack_a);
void				ft_sa_check(t_stack **stack_a);
void				ft_sb_check(t_stack **stack_b);
void				ft_ss_check(t_stack **stack_a, t_stack **stack_b);
void				ft_pa_check(t_stack **stack_b, t_stack **stack_a);
void				ft_pb_check(t_stack **stack_a, t_stack **stack_b);
void				ft_ra_check(t_stack **stack_a);
void				ft_rb_check(t_stack **stack_b);
void				ft_rr_check(t_stack **stack_a, t_stack **stack_b);
void				ft_rra_check(t_stack **stack_a);
void				ft_rrb_check(t_stack **stack_b);
void				ft_rrr_check(t_stack **stack_a, t_stack **stack_b);
char				*get_next_line(int fd);
char				*scan(int fd, char *s);
char				*next(char *s);
char				*line(char *str);
char				*add(char *s1, char *s2);
void				ft_check_number(t_stack **stack_a);

long int			ft_atol(const char *str);
long int			ft_isdigit_atol(long int c);
static int			spc_chrc_atol(char c);
void				go_next(t_stack **last, t_stack **tmp);

int					count_the_signs(int argc, char *argv, int *j, int *i);
int					checkisnumber(int argc, char **argv);
#endif