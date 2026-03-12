/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 16:03:03 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/12 15:46:10 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rvr(t_stack **stack)
{
	t_stack	*ptr;
	t_stack	*first;
	t_stack	*second;

	ptr = *stack;
	second = *stack;
	while (ptr->next->next)
		ptr = ptr->next;
	first = ptr->next;
	ptr->next = NULL;

	first->next = second;
	*stack = first;
}

void	reverse_rotate_a(t_stack **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	rvr(stack_a);
	ft_printf("rra\n");
}

/*
void	reverse_rotate_b(t_stack *stack_b)
{
	rvr(stack_b);
	//ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rvr(stack_a);
	rvr(stack_b);
	//ft_printf("rrr\n");
}
*/