/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:17:47 by ydegerli          #+#    #+#             */
/*   Updated: 2023/03/09 13:34:42 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*lis_helper(int *lis, int size)
{
	int	i;

	i = -1;
	lis = (int *)malloc(sizeof(int) * size);
	while (++i < size)
		lis[i] = 1;
	return (lis);
}

int	*lis_helper_one(int *prev, int size)
{
	int	i;

	i = -1;
	prev = (int *)malloc(sizeof(int) * size);
	while (++i < size)
		prev[i] = -1;
	return (prev);
}

void	lis_helper_two(int *dst, int *prev, int *lis, int size)
{
	int	i;
	int	j;

	i = 0;
	while (++i < size)
	{
		j = -1;
		while (++j < i)
		{
			if (dst[i] > dst[j] && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
				prev[i] = j;
			}
		}
	}
}

int	lis_helper_three(int *lis, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++j < size)
	{
		if (lis[i] <= lis[j])
			i = j;
	}
	return (i);
}

int	*lis(int *dst, int size, int *len)
{
	int	i;
	int	j;
	int	*lis;
	int	*prev;
	int	*lis_seq;

	lis = lis_helper(lis, size);
	prev = lis_helper_one(prev, size);
	lis_helper_two(dst, prev, lis, size);
	i = lis_helper_three(lis, size);
	if (!lis[i])
		return (NULL);
	*len = lis[i];
	j = *len - 1;
	lis_seq = malloc(sizeof(int) * (*len));
	while (i >= 0)
	{
		lis_seq[j--] = dst[i];
		i = prev[i];
	}
	free(lis);
	free(prev);
	return (lis_seq);
}
