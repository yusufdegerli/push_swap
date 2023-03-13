/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:03:42 by ydegerli          #+#    #+#             */
/*   Updated: 2023/03/05 16:19:02 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **stack_a)
{
	int		i;
	int		j;
	int		x;
	t_stack	*tmp;

	tmp = NULL;
	i = 0;
	j = 0;
	x = 0;
	while (!(i < j && j < x && x > i))
	{
		tmp = *stack_a;
		i = tmp->value;
		tmp = tmp->next;
		j = tmp->value;
		tmp = tmp->next;
		x = tmp->value;
		if ((i > j && j < x && x > i)
			|| (i > j && j > x && x < i) || (i < j && j > x && x > i))
			ft_sa(stack_a);
		if (i > j && j < x && x < i)
			ft_ra(stack_a);
		if (i < j && j > x && x < i)
			ft_rra(stack_a);
	}
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 2;
	while (i-- > 0)
		ft_pb(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_move_to_a(stack_a, stack_b);
	ft_search_min(stack_a, ft_stacksize(*stack_a));
}
