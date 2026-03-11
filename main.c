/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:09:58 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/11 15:25:06 by lheteau          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	char	**raw_stack;
	t_stack	*stack_a;
	t_stack	*stack_b;
	//t_stack *ptr;

	(void)argv;
	if (argc < 2)
		return (1);
	raw_stack = NULL;
	raw_stack = get_stack(raw_stack, argv);
	if (raw_stack == NULL)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	lst_get_list(&stack_a, raw_stack);
	free_tab(raw_stack);
	radix_sort_test(&stack_a, &stack_b);
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
	}*/
	lst_free(stack_a);
}
