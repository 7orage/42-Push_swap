/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_mini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:26:27 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/12 17:28:10 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	one;
	int	two;
	int	three;

	one = (*stack_a)->value;
	two = (*stack_a)->next->value;
	three = (*stack_a)->next->next->value;
	if (one > two && two < three && one < three)
		swap_a(stack_a);
	else if (one > two && two > three)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (one > two && two < three && one > three)
		rotate_a(stack_a);
	else if (one < two && two > three && one < three)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (one < two && two > three && one > three)
		reverse_rotate_a(stack_a);
}

void	sort_five(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	push_b(stack_a, &stack_b);
	push_b(stack_a, &stack_b);
	sort_three(stack_a);
	if (stack_b->index > stack_b->next->index)
		swap_b(&stack_b);
	while (stack_b)
	{
		if (stack_b->index > (*stack_a)->index)
			while (stack_b->index > (*stack_a)->index)
				rotate_a(stack_a);
		push_a(stack_a, &stack_b);
	}
	while ((*stack_a)->index != 0)
		rotate_a(stack_a);
}

