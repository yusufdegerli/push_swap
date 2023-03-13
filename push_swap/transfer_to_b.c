/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:04:33 by ydegerli          #+#    #+#             */
/*   Updated: 2023/03/10 12:26:56 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_the_signs(int argc, char *argv, int *j, int *i)
{
	int	c;
	int	k;

	k = -1;
	c = 0;
	while (argv[++k])
		if (argv[k] == '-' || argv[k] == '+')
			c++;
	if (c > 1)
		*j = 1;
	if ((c == 1) && (argv[0] == '-' || argv[0] == '+')
		&& (ft_atoi(argv) != 0))
	{
		j = 0;
		*i += 1;
	}
	return (c);
}

int	not_on_lis(t_stack *stack_a, int size_a, int *lis_ar, int lis_size)
{
	int	pos;
	int	i;

	pos = 0;
	while (stack_a != NULL)
	{
		i = 0;
		while (stack_a->value != lis_ar[i] && i < lis_size)
		{
			if (i == lis_size - 1)
				return (pos);
			i++;
		}
		stack_a = stack_a->next;
		pos++;
	}
	size_a = -1;
	return (size_a);
}

void	ft_move_to_b(t_stack **stack_a, t_stack **stack_b, int *a, int mx)
{
	int	i;
	int	size_a;

	size_a = ft_stacksize(*stack_a);
	i = not_on_lis(*stack_a, size_a, a, mx);
	while (i != -1)
	{
		if (i > 0)
		{
			if (i < size_a / 2)
			{
				while (i-- > 0)
					ft_ra(stack_a);
			}
			else
			{
				while (i-- > 0)
					ft_rra(stack_a);
			}
		}
		ft_pb(stack_a, stack_b);
		i = not_on_lis(*stack_a, --size_a, a, mx);
	}
}
