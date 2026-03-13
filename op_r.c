/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 16:02:06 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/13 13:28:06 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// SHIFT UP ALL ELEMENTS OF STACK BY 1 (n1 -> nf)
static void	rotate(t_stack **stack)
{
	t_stack	*ptr;
	t_stack	*first;

	first = *stack;
	*stack = first->next;
	ptr = *stack;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = first;
	first->next = NULL;
}

void	rotate_a(t_stack **stack_a)
{
	if (!*stack_a || !stack_a || !(*stack_a)->next)
		return ;
	rotate(stack_a);
	ft_printf("ra\n");
}
