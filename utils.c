/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:28:54 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/09 15:21:41 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	check_arg(stack);
	tmp = stack;
	stack_f = ft_split(stack, ' ');
	free(stack);
	return (stack_f);
}

void	check_arg(char *stack)
{
	int i;

	i = 0;
	while (stack[i])
	{
		if (ft_isdigit(stack[i]) == 0 && stack[i] != ' ')
			ft_error("Wrong character in argument");
		i++;
	}
}