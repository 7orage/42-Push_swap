/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:23:48 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/11 15:26:45 by lheteau          ###   ########.fr       */
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

// ADD A NEW VALUE TO THE LISTE
void	lst_new_val(t_stack **stack_a, int value)
{
	t_stack	*new;
	t_stack	*ptr;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
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

void	lst_get_list(t_stack **stack_a, char **raw_stack)
{
	int					i;

	i = 0;
	while (raw_stack[i])
	{
		lst_new_val(stack_a, ft_atoi(raw_stack[i]));
		i++;
	}
	set_index(stack_a, i);
}
