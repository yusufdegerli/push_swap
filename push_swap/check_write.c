/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:00:57 by ydegerli          #+#    #+#             */
/*   Updated: 2023/03/12 13:41:25 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstcheck_c(t_stack *stack_a, int check)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->value == check)
			ft_display_exit();
		stack_a = stack_a->next;
	}
	return ;
}

static void	ft_lst_order_c(t_stack **stack_a)
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
}

void	ft_check_lst_inverted(t_stack **stack_a)
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
	ft_sa_check(stack_a);
	return ;
}

int	checkisnumber(int argc, char **argv)
{
	int	i;
	int	j;
	int	c;

	j = 0;
	while (--argc != 0)
	{
		i = -1;
		c = count_the_signs(argc, argv[argc], &j, &i);
		if (j == 1)
			break ;
		while (argv[argc][++i])
		{
			if ((argv[argc][i] > '9' || argv[argc][i] < '0')
				|| (ft_strlen(argv[argc]) != 2 && ft_atoi(argv[argc]) == -1))
			{
				j = 1;
				break ;
			}
		}
	}
	return (j);
}

void	ft_check_write_lst(t_stack **stack_a, int argc, char **argv, int i)
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
	tmp = NULL;
}
