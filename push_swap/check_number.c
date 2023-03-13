/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:31:27 by ydegerli          #+#    #+#             */
/*   Updated: 2023/03/08 15:06:26 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_number(t_stack **stack_a)
{
	size_t	i;
	t_stack	*tmp_a;

	i = 0;
	tmp_a = *stack_a;
	if (tmp_a == NULL)
		return ;
	while (tmp_a != NULL && tmp_a->next != NULL)
	{
		if ((tmp_a->value < tmp_a->next->value))
		{
			tmp_a = tmp_a->next;
			i++;
		}
	}
	if (i == ft_stacksize(*stack_a))
	{
		write(1, "OK\n", 3);
		ft_display_exit();
	}
	ft_display_exit();
}
