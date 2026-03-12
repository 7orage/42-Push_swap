/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:28:54 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/12 21:42:20 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// INIT THE RAW STACK
char	**get_stack(char **stack_f, char **argv)
{
	char	*tmp;
	char	*stack;
	int		i;

	i = 1;
	stack = ft_strdup("");
	while (argv[i])
	{
		tmp = stack;
		stack = ft_strjoin(stack, " ");
		free(tmp);
		tmp = stack;
		stack = ft_strjoin(stack, argv[i]);
		free(tmp);
		i++;
	}
	check_num(stack);
	tmp = stack;
	stack_f = ft_split(stack, ' ');
	free(stack);
	return (stack_f);
}
