/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:04:22 by ydegerli          #+#    #+#             */
/*   Updated: 2023/03/12 13:40:56 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_inverted(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack_a;
	tmp2 = tmp->next;
	while (tmp2 != NULL)
	{
		if (tmp->value < tmp2->value)
			return ;
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	ft_sa(stack_a);
	return ;
}

void	ft_stack_order(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack_a;
	tmp2 = tmp->next;
	while (tmp2 != NULL)
	{
		if (tmp->value > tmp2->value)
			return ;
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	exit(0);
}

void	ft_stackcheck(t_stack *stack_a, int check)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->value == check)
			ft_display_exit();
		stack_a = stack_a->next;
	}
	return ;
}

void	ft_write_lst(t_stack **stack_a, int argc, char **argv, int i)
{
	t_stack	*tmp;

	tmp = NULL;
	while (i < argc)
	{
		if ((ft_atol(argv[i]) < INT32_MIN) || (ft_atol(argv[i]) > INT32_MAX))
			ft_display_exit();
		if (*argv[i] >= '0' && *argv[i] <= '9' || *argv[i] == '-')
		{
			tmp = ft_stacknew(ft_atol(argv[i]));
			if (checkisnumber(argc, argv))
				ft_display_exit();
		}	
		else
			ft_display_exit();
		ft_stackadd_back(stack_a, tmp);
		ft_stackcheck(*stack_a, tmp->value);
		i++;
	}
	if (i == 0)
		ft_display_exit();
	ft_stack_order(stack_a);
	ft_stack_inverted(stack_a);
	tmp = NULL;
}

void	ft_stack_delete(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL)
		return ;
	tmp = *stack;
	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		free (*stack);
		*stack = tmp;
	}
}
