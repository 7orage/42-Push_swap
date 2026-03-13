/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:23:48 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/13 13:58:05 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// FREE THE LIST
void	lst_free(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

// GET THE SIZE OF THE LIST
int	lst_get_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

// ADD A NEW VALUE TO THE LISTE
int	lst_new_val(t_stack **stack_a, long int value)
{
	t_stack	*new;
	t_stack	*ptr;

	if (value < INT_MIN || value > INT_MAX)
		return (0);
	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	if (!*stack_a)
		*stack_a = new;
	else
	{
		ptr = *stack_a;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
	return (1);
}

// INIT THE VALUE LIST
static void	set_index(t_stack **stack_a, int i)
{
	t_stack	*high;
	t_stack	*tp;

	while (i--)
	{
		high = NULL;
		tp = *stack_a;
		while (tp)
		{
			if (tp->index < 0 && (high == NULL || tp->value > high->value))
				high = tp;
			tp = tp->next;
		}
		if (high)
			high->index = i;
	}
}

//
int	lst_get_list(t_stack **stack_a, char **raw_stack)
{
	int	i;

	i = 0;
	while (raw_stack[i])
	{
		if (lst_new_val(stack_a, ft_atol(raw_stack[i])) == 0)
			return (0);
		i++;
	}
	set_index(stack_a, i);
	return (1);
}
