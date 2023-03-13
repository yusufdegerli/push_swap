/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:03:57 by ydegerli          #+#    #+#             */
/*   Updated: 2023/03/12 13:22:22 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacklast(t_stack *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	last = ft_stacklast(*lst);
	if (last)
		last->next = new;
	else
		*lst = new;
}

t_stack	*ft_stacknew(long int content)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = (int)content;
	node->next = NULL;
	return (node);
}

int	ft_stacksize(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	addlist(t_stack **stack_a, int ac, char **av)
{
	t_stack	*tmp;

	while (--ac > 0)
	{
		tmp = ft_stacknew(ft_atoi(av[ac]));
		ft_stackadd_front(stack_a, tmp);
	}
}
