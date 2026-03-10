/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:31:06 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/10 12:42:53 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*tmp;

	tmp = *stack_1;
	*stack_1 = (*stack_1)->next;
	tmp->next = *stack_2;
	*stack_2 = tmp;
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_b || !stack_b)
		return ;
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !stack_a)
		return ;
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
