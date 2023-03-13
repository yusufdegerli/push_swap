/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:00:26 by ydegerli          #+#    #+#             */
/*   Updated: 2023/03/09 12:37:46 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_check(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack_a;
	tmp2 = tmp->next;
	*stack_a = tmp2;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	return ;
}

void	ft_sb_check(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack_b;
	tmp2 = tmp->next;
	*stack_b = tmp2;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	return ;
}

void	ft_ss_check(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack_a;
	tmp2 = tmp->next;
	*stack_a = tmp2;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	tmp = NULL;
	tmp2 = NULL;
	tmp = *stack_b;
	tmp2 = tmp->next;
	*stack_b = tmp2;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	return ;
}

void	ft_pa_check(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	return ;
}

void	ft_pb_check(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_a == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	return ;
}
