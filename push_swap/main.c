/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:48:08 by ydegerli          #+#    #+#             */
/*   Updated: 2023/03/12 14:20:13 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_split(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	*dst;
	int	size_b;
	int	i;
	int	*a;

	i = 0;
	if (size == 3)
	{
		ft_sort_three(stack_a);
		return ;
	}
	if (size == 5)
	{
		ft_sort_five(stack_a, stack_b);
		return ;
	}
	size = ft_stacksize(*stack_a);
	dst = ft_copy_cont(*stack_a, size);
	a = lis(dst, size, &i);
	ft_move_to_b(stack_a, stack_b, a, i);
	ft_move_to_a(stack_a, stack_b);
	ft_search_min(stack_a, size);
	free(dst);
	free(a);
}

void	ft_check_argv(int argc, char **argv, t_stack **stack_a)
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
		ft_write_lst(stack_a, size, arg, 0);
		free(arg);
	}
	else if (argc >= 3)
		ft_write_lst(stack_a, argc, argv, 1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**arg;
	int		size;

	size = 0;
	stack_a = NULL;
	stack_b = NULL;
	arg = NULL;
	if (argc < 2)
	{
		ft_display_exit();
		return (0);
	}
	else
		ft_check_argv(argc, argv, &stack_a);
	size = ft_stacksize(stack_a);
	if (size == 2)
		return (0);
	ft_list_split(&stack_a, &stack_b, size);
	ft_stack_delete(&stack_a);
	ft_stack_delete(&stack_b);
	return (0);
}
