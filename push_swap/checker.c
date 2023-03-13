/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:01:25 by ydegerli          #+#    #+#             */
/*   Updated: 2023/03/12 14:21:47 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr_or_death(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strcmp(str, "rra\n"))
		ft_rra_check(stack_a);
	else if (ft_strcmp(str, "rrb\n"))
		ft_rrb_check(stack_b);
	else if (ft_strcmp(str, "rrr\n"))
		ft_rrr_check(stack_a, stack_b);
	else
		ft_display_exit();
}

void	ft_exec_sort(t_stack **stack_a, t_stack **stack_b, char *str)
{
	while (str != NULL)
	{
		if (ft_strcmp(str, "sa\n"))
			ft_sa_check(stack_a);
		else if (ft_strcmp(str, "sb\n"))
			ft_sb_check(stack_b);
		else if (ft_strcmp(str, "ss\n"))
			ft_ss_check(stack_a, stack_b);
		else if (ft_strcmp(str, "pa\n"))
			ft_pa_check(stack_b, stack_a);
		else if (ft_strcmp(str, "pb\n"))
			ft_pb_check(stack_a, stack_b);
		else if (ft_strcmp(str, "ra\n"))
			ft_ra_check(stack_a);
		else if (ft_strcmp(str, "rb\n"))
			ft_rb_check(stack_b);
		else if (ft_strcmp(str, "rr\n"))
			ft_rr_check(stack_a, stack_b);
		else
			ft_rrr_or_death(stack_a, stack_b, str);
		str = get_next_line(0);
	}
}

void	ft_check_sort(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->value > (stack_a->next)->value)
		{
			write(1, "KO\n", 3);
			return ;
		}
		stack_a = stack_a->next;
	}
	write(1, "OK\n", 3);
	return ;
}

void	ft_check_argv_c(int argc, char **argv, t_stack **stack_a)
{
	int		size;
	char	**arg;

	arg = NULL;
	size = 0;
	if (argc == 2)
	{
		arg = ft_split(argv[1], ' ');
		while (arg[size] != NULL)
			size++;
		ft_check_write_lst(stack_a, size, arg, 0);
		free(arg);
	}
	else if (argc >= 3)
		ft_check_write_lst(stack_a, argc, argv, 1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*str;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
	{
		ft_display_exit();
		return (0);
	}
	else
		ft_check_argv_c(argc, argv, &stack_a);
	str = get_next_line(0);
	ft_exec_sort(&stack_a, &stack_b, str);
	ft_check_sort(stack_a);
	return (0);
}
