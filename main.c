/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:09:58 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/10 15:01:59 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *s)
{
	write(1, "Error\n", 6);
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}
/*
void	align(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_a)
	{
		push_b(stack_a, stack_b);
		rotate_b(stack_b);
	}
}*/

int	main(int argc, char **argv)
{
	char	**raw_stack;
	t_stack	*stack_a;
	t_stack	*stack_b;
	//t_stack *ptr;

	(void)argv;
	if (argc == 1)
		ft_error("Wrong number of argument");
	raw_stack = NULL;
	raw_stack = get_stack(raw_stack, argv);
	stack_a = NULL;
	stack_b = NULL;
	lst_get_list(&stack_a, raw_stack);
	
	/*
	ptr = stack_a;
	ft_printf("\n\n VALUE A --D\n");
	while (ptr)
	{
		ft_printf("value a before %d\n", ptr->value);
		ptr = ptr->next;
	}*/

	radix_sort_test(&stack_a, &stack_b);
	//align(&stack_a, &stack_b);
	/*
	ptr = stack_a;
	ft_printf("\n\n VALUE A --F\n");
	while (ptr)
	{
		ft_printf("value a %d\n", ptr->value);
		ptr = ptr->next;
	}
	ptr = stack_b;
	ft_printf("\n\n VALUE B --F\n");
	while (ptr)
	{
		ft_printf("value b %d\n", ptr->value);
		ptr = ptr->next;
	}
*/
}
