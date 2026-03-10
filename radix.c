/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:35:58 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/10 13:18:15 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	print_list(t_stack *head)
{
	while (head)
	{
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}

int	get_stack_size(t_stack *stack)
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

// Radix Sort adapté aux opérations de piles
void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int i;
	int j;
	int size;
	int max_bits;
	t_stack	*ptr;
	
	if (!stack_a || !*stack_a)
		return ;

	size = get_stack_size(*stack_a);

	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	// 2. Boucle sur chaque bit (de 0 au max_bits)
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size && *stack_a != NULL)
		{
			// On regarde si le bit i de la valeur est 0 ou 1
			if ((((*stack_a)->value >> i) & 1) == 1)
			{
				rotate_a(stack_a);
			}
			else
			{
				push_b(stack_a, stack_b);
			}
			j++;
		}

		// On ramène tout de B vers A pour le prochain bit
		while (*stack_b)
		{
			push_a(stack_a, stack_b);
		}
		i++;
	}
	ptr = *stack_a;
	ft_printf("\n\n VALUE A --R\n");
	while (ptr)
	{
		ft_printf("value a dn radix %d\n", ptr->value);
		ptr = ptr->next;
	}
	ptr = *stack_b;
	ft_printf("\n\n VALUE B --R\n");
	while (ptr)
	{
		ft_printf("value b dn radix%d\n", ptr->value);
		ptr = ptr->next;
	}
}