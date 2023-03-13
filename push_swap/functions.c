/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:01:57 by ydegerli          #+#    #+#             */
/*   Updated: 2023/03/02 18:01:58 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *src)
{
	int	tmp;

	tmp = src->value;
	src->value = src->next->value;
	src->next->value = tmp;
	tmp = src->index;
	src->index = src->next->index;
	src->next->index = tmp;
}

void	rotate(t_stack *src)
{
	t_stack	*tmp_p;
	int		tmp;
	int		i;

	tmp_p = src;
	i = 0;
	tmp = src->value;
	while (i < src->stack_size - 1)
	{
		src->value = src->next->value;
		src = src->next;
		i++;
	}
	src->value = tmp;
	i = 0;
	tmp = tmp_p->index;
	while (i < tmp_p->stack_size - 1)
	{
		tmp_p->index = tmp_p->next->index;
		tmp_p = tmp_p->next;
		i++;
	}
	tmp_p->index = tmp;
}

void	reverse_rotate(t_stack *src)
{
	t_stack	*tmp_p;
	int		tmp;
	int		i;

	tmp_p = src;
	i = 0;
	tmp = src->value;
	while (i < src->stack_size - 1)
	{
		src->value = src->before->value;
		src = src->before;
		i++;
	}
	src->value = tmp;
	i = 0;
	tmp = tmp_p->index;
	while (i < tmp_p->stack_size - 1)
	{
		tmp_p->index = tmp_p->before->index;
		tmp_p = tmp_p->before;
		i++;
	}
	tmp_p->index = tmp;
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}
