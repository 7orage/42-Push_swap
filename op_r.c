/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 16:02:06 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/11 15:18:23 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// SHIFT UP ALL ELEMENTS OF STACK BY 1
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
/*
void	rotate_b(t_stack **stack_b)
{
	if (!*stack_b || !stack_b || !(*stack_b)->next)
		return ;
	rotate(stack_b);
	ft_printf("rb\n");
}
*/
/*
void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
*/