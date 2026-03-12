/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:09:58 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/12 20:39:16 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *s)
{
	(void)s;
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	char	**raw_stack;
	t_stack	*stack_a;
	t_stack	*stack_b;
	//t_stack *ptr;
	int		i;

	i = 0;

	(void)argv;
	if (argc < 2)
		return (1);
	raw_stack = NULL;
	raw_stack = get_stack(raw_stack, argv);
	if (raw_stack == NULL)
		return (1);
	stack_a = NULL;
	if (lst_get_list(&stack_a, raw_stack) == 0)
	{
		free_tab(raw_stack);
		lst_free(stack_a);
		ft_error("Int value forbidden");
	}
	free_tab(raw_stack);
	if (check_tri(&stack_a) == 0)
	{
		lst_free(stack_a);
		return (1);
	}
	stack_b = NULL;
	if (check_dup(&stack_a) == 1)
	{
		if (lst_get_size(stack_a) == 2)
			swap_a(&stack_a);
		else if (lst_get_size(stack_a) == 3)
			sort_three(&stack_a);
		else if (lst_get_size(stack_a) == 4)
			sort_four(&stack_a);
		else if (lst_get_size(stack_a) == 5)
		{
			sort_five(&stack_a);
		}
		else
			radix_sort(&stack_a, &stack_b);
	}
	else
	{
		lst_free(stack_a);
		ft_error("Checks null");
	}
	/*
	ptr = stack_a;
	ft_printf("\n\n VALUE A --F\n");
	while (ptr)
	{
		ft_printf("value a %d\n", (int)ptr->value);
		ptr = ptr->next;
	}*/
	lst_free(stack_a);
	return (0);
}
