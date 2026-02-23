/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 16:03:03 by lheteau           #+#    #+#             */
/*   Updated: 2026/02/23 18:34:23 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rvr(t_stack *stack)
{
	t_stack	*ptr;

	ptr = stack;
	while (ptr->next->next)
		ptr = ptr->next;
	ptr->next->next = stack;
	ptr->next = NULL;
}

void	rra(t_stack *stack_a)
{
	rvr(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack *stack_b)
{
	rvr(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rvr(stack_a);
	rvr(stack_b);
	ft_printf("rrr\n");
}
