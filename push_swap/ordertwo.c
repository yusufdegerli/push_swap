/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordertwo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:03:25 by ydegerli          #+#    #+#             */
/*   Updated: 2023/03/02 18:03:26 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_intcpy(int *src, int n)
{
	int	i;
	int	*dst;

	dst = malloc(sizeof(int) * n);
	if (!dst || !src)
		ft_display_exit();
	i = -1;
	while (++i < n)
		dst[i] = src[i];
	return (dst);
}

int	ft_move_a(int a, int b, t_stack **stack_a, t_stack **stack_b)
{
	while (a < 0 && b < 0)
	{
		ft_rrr(stack_a, stack_b);
		a++;
		b++;
	}
	while (a > 0 && b > 0)
	{
		ft_rr(stack_a, stack_b);
		a--;
		b--;
	}
	if (a < 0)
		while (a++ < 0)
			ft_rra(stack_a);
	else if (a > 0)
		while (a-- > 0)
			ft_ra(stack_a);
	return (b);
}

void	ft_search_min(t_stack **stack_a, int size)
{
	int		pos;
	int		pos_min;
	int		min;
	t_stack	*tmp;

	pos_min = 0;
	pos = 0;
	tmp = *stack_a;
	min = tmp->value;
	while (pos < size)
	{
		if (min > tmp->value)
		{
			min = tmp->value;
			pos_min = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	tmp = NULL;
	pos = ft_the_needed_b(pos_min, size);
	ft_move_a(pos, 0, stack_a, &tmp);
}
