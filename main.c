/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:09:58 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/14 13:13:12 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// HANDLE ERROR
void	ft_error(char *s)
{
	(void)s;
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

// MANAGE THE SORTING TO THE RADIX
static void	check_by_size(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (lst_get_size(*stack_a) == 2)
		swap_a(stack_a);
	else if (lst_get_size(*stack_a) == 3)
		sort_three(stack_a);
	else if (lst_get_size(*stack_a) == 4)
		sort_four(stack_a);
	else if (lst_get_size(*stack_a) == 5)
		sort_five(stack_a);
	else
		radix_sort(stack_a, &stack_b);
}

//
static int	checks_manage(t_stack **stack_a)
{
	if (check_tri(stack_a) == 0)
	{
		if (check_dup(stack_a) == 0)
		{
			lst_free(*stack_a);
			ft_error("I smell deviousness");
		}
		lst_free(*stack_a);
		return (0);
	}
	if (check_dup(stack_a) == 1)
		check_by_size(stack_a);
	else
	{
		lst_free(*stack_a);
		ft_error("Checks null");
	}
	return (1);
}

// MAIN
int	main(int argc, char **argv)
{
	char	**raw_stack;
	t_stack	*stack_a;

	(void)argv;
	if (argc < 2)
		return (1);
	if (argv[1][0] == '\0')
		ft_error("Fill the argv for the next time");
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
	if (checks_manage(&stack_a) == 0)
		return (1);
	lst_free(stack_a);
	return (0);
}
