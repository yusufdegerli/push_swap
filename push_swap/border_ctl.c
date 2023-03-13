/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_ctl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:43:09 by ydegerli          #+#    #+#             */
/*   Updated: 2023/03/09 14:31:19 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_isdigit_atol(long int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	spc_chrc_atol(char c)
{
	if ((c == ' ' || c == '\t' || c == '\r'
			|| c == '\n' || c == '\v' || c == '\f'))
		return (1);
	return (0);
}

long int	ft_atol(const char *str)
{
	int		i;
	long	num;
	int		neg;

	neg = 1;
	i = 0;
	num = 0;
	while (spc_chrc_atol(str[i]) == 1)
		i++;
	if (str[i] == '-')
		neg *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit_atol(str[i]))
	{
		num = (num * 10) + str[i++] - 48;
	}
	return (neg * num);
}
