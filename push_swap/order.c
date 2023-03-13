/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:03:14 by ydegerli          #+#    #+#             */
/*   Updated: 2023/03/02 18:03:16 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_best_comb_helper(int *arr_a, int *arr_b, int *tmp, int size)
{
	int	i;
	int	pos;

	pos = 0;
	i = -1;
	while (++i < size)
	{
		if (tmp[i] < tmp[pos])
		pos = i;
	}
	free (arr_a);
	free (arr_b);
	free (tmp);
	return (pos);
}

int	ft_max_nbr(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a > b)
		return (a);
	if (b > a)
		return (b);
	else
		return (a);
}

int	return_max_or_min(int cont, int *max_n_min, int size)
{
	if (cont > max_n_min[0])
		return (max_n_min[2]);
	if (cont < max_n_min[1])
		return (max_n_min[3]);
	return (size + 1);
}

int	ft_max_or_min(t_stack *stack_a, int cont, int size)
{
	int	max_n_min[5];

	max_n_min[0] = stack_a->value;
	max_n_min[1] = stack_a->value;
	max_n_min[2] = 0;
	max_n_min[3] = 0;
	max_n_min[4] = 1;
	while (stack_a != NULL)
	{
		if (stack_a->value >= max_n_min[0])
		{
			max_n_min[0] = stack_a->value;
			max_n_min[2] = max_n_min[4];
		}
		if (stack_a->value < max_n_min[1])
		{
			max_n_min[1] = stack_a->value;
			max_n_min[3] = max_n_min[4] - 1;
		}
		stack_a = stack_a->next;
		max_n_min[4]++;
	}
	return (return_max_or_min(cont, max_n_min, size));
}

int	ft_best_comb(int *arr_a, int *arr_b, int size)
{
	int	*tmp;
	int	i;

	i = -1;
	tmp = (int *)malloc(sizeof(int) * size);
	if (!tmp || !arr_a || !arr_b)
		ft_display_exit();
	while (++i < size)
	{
		if ((arr_a[i] > 0 && arr_b[i] > 0)
			|| (arr_a[i] < 0 && arr_b[i] < 0))
			tmp[i] = ft_max_nbr(arr_a[i], arr_b[i]);
		else
		{
			if (arr_a[i] < 0)
				arr_a[i] *= -1;
			if (arr_b[i] < 0)
				arr_b[i] *= -1;
			tmp[i] = arr_a[i] + arr_b[i];
		}
	}
	return (ft_best_comb_helper(arr_a, arr_b, tmp, size));
}
