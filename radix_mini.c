/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_mini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:26:27 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/13 13:58:56 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ISOLATE THE LOWEST INDEX
static int	get_index(t_stack *ptr)
{
	int		ind;
	int		pos;
	int		pos_r;

	pos = 1;
	ind = 1;
	while (ptr)
	{
		if (ptr->index <= ind)
		{
			ind = ptr->index;
			pos_r = pos;
		}
		ptr = ptr->next;
		pos++;
	}
	return (pos_r);
}

//
void	push_min_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*ptr;
	int			pos_r;
	int			size;

	ptr = *stack_a;
	size = lst_get_size(*stack_a);
	pos_r = get_index(ptr);
	if (pos_r <= 2 && pos_r != 1)
	{
		while (pos_r > 1)
		{
			rotate_a(stack_a);
			pos_r--;
		}
	}
	else if (pos_r != 1)
	{
		while (size - pos_r >= 0)
		{
			reverse_rotate_a(stack_a);
			pos_r++;
		}
	}
	push_b(stack_a, stack_b);
}

// SORT THREE NUMBERS 
void	sort_three(t_stack **stack_a)
{
	int	one;
	int	two;
	int	three;

	one = (*stack_a)->index;
	two = (*stack_a)->next->index;
	three = (*stack_a)->next->next->index;
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

// SORT FOUR NUMBERS
void	sort_four(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	push_min_to_b(stack_a, &stack_b);
	sort_three(stack_a);
	push_a(stack_a, &stack_b);
}

// SORT FIVE NUMBERS
void	sort_five(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	push_min_to_b(stack_a, &stack_b);
	sort_four(stack_a);
	push_a(stack_a, &stack_b);
}
