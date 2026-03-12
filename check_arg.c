/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:46:44 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/12 14:49:00 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// CHECK IF ONLY NUMBER (MINUS INCLUDES)
static int	ft_isdigit_int(int c)
{
	if (c == '-')
		return (2);
	if (c < 48 || c > 57)
		return (0);
	return (1);
}

void	check_num(char *stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (ft_isdigit_int(stack[i]) == 2)
		{
			if (ft_isdigit_int(stack[i + 1]) != 1)
			{
				free(stack);
				ft_error("Wrong character in argument");
			}
		}
		else if (ft_isdigit_int(stack[i]) == 0 && stack[i] != ' ')
		{
			free(stack);
			ft_error("Wrong character in argument");
		}
		i++;
	}
}

// CHECK IF n1 < n2 < n3 ... < nf
int	check_tri(t_stack **stack_a)
{
	t_stack	*current;

	current = *stack_a;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (1);
		current = (current)->next;
	}
	return (0);
}

// CHECK IF DUPLICATES / -32768 < NBR > 32767
int	check_dup(t_stack **stack_a)
{
	t_stack	*current;

	current = *stack_a;
	while (current->next)
	{
		if (current->value == current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
