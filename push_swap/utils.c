/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:04:42 by ydegerli          #+#    #+#             */
/*   Updated: 2023/03/08 15:09:33 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_copy_cont(t_stack *stack_a, int size)
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * size + 1);
	if (!arr)
		ft_display_exit();
	while (stack_a != NULL)
	{
		arr[i++] = (stack_a)->value;
		stack_a = (stack_a)->next;
	}
	return (arr);
}

void	ft_display_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	my_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
		nb--;
	return (nb);
}

int	ft_the_needed_b(int max, int size)
{
	if (max > (size / 2))
		max = max - size;
	return (max);
}

int	ft_the_needed_a(t_stack *stack_a, int cont, int size)
{
	t_stack	*tmp;
	int		i;

	tmp = stack_a;
	i = ft_max_or_min(tmp, cont, size);
	if (i != size + 1)
		return (ft_the_needed_b(i, size));
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (cont < stack_a->value && cont > tmp->value)
		return (0);
	i = 1;
	while (!(cont > stack_a->value && cont < (stack_a->next)->value))
	{
		stack_a = stack_a->next;
		i++;
	}
	return (ft_the_needed_b(i, size));
}
