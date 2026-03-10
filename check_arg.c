/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:46:44 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/10 16:10:55 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit_int(int c)
{
	if (c == '-')
		return (2);
	if (c < 48 || c > 57)
		return (0);
	return (1);
}

void	check_arg(char *stack)
{
	int i;

	i = 0;
	while (stack[i])
	{
		if (ft_isdigit_int(stack[i]) == 2)
		{
			if (ft_isdigit_int(stack[i + 1]) != 1)
				ft_error("Wrong character in argument");
		}
		else if (ft_isdigit_int(stack[i]) == 0 && stack[i] != ' ')
			ft_error("Wrong character in argument");
		i++;
	}
}
