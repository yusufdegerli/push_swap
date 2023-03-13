/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:02:38 by ydegerli          #+#    #+#             */
/*   Updated: 2023/03/05 16:18:54 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_best_nbr_b(t_stack **s_b, int size_b, t_stack **s_a, int si_a)
{
	int		*arr_b;
	int		*arr_a;
	t_stack	*tmp_b;
	int		i;

	i = -1;
	tmp_b = *s_b;
	arr_a = (int *)malloc(sizeof(int) * (si_a + size_b + 100));
	arr_b = (int *)malloc(sizeof(int) * size_b);
	if (!arr_a || !arr_b)
		ft_display_exit();
	while (++i < size_b)
		arr_b[i] = ft_the_needed_b(i, size_b);
	i = -1;
	while (++i < size_b && tmp_b != NULL)
	{
		arr_a[i] = ft_the_needed_a(*s_a, tmp_b->value, si_a);
		tmp_b = tmp_b->next;
	}
	i = ft_best_comb(ft_intcpy(arr_a, size_b), ft_intcpy(arr_b, size_b),
			size_b);
	i = ft_move_a(arr_a[i], arr_b[i], s_a, s_b);
	free(arr_a);
	free(arr_b);
	return (i);
}

void	ft_move_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	size_a;
	int	size_b;

	i = 0;
	size_a = ft_stacksize(*stack_a);
	size_b = ft_stacksize(*stack_b);
	while (*stack_b != NULL)
	{
		i = ft_best_nbr_b(stack_b, size_b, stack_a, size_a);
		if (i < 0)
			while (i++ < 0)
				ft_rrb(stack_b);
		else if (i > 0)
			while (i-- > 0)
				ft_rb(stack_b);
		ft_pa(stack_b, stack_a);
		size_a++;
		size_b--;
	}
}
