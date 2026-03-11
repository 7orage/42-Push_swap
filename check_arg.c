/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:46:44 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/11 15:30:08 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// CHECK IF ONLY NUMBER (MINUS INCLUDES)
static int	ft_isdigit_int(int c)
{
	if (c == '-')
		return (2);
	if (c < 48 || c > 57)
		return (0);
	return (1);
}

void	check_num(char *stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (ft_isdigit_int(stack[i]) == 2)
		{
			if (ft_isdigit_int(stack[i + 1]) != 1)
			{
				free(stack);
				ft_error("Wrong character in argument");
			}
		}
		else if (ft_isdigit_int(stack[i]) == 0 && stack[i] != ' ')
		{
			free(stack);
			ft_error("Wrong character in argument");
		}
		i++;
	}
}

// CHECK IF DUPLICATES / -32768 < NBR > 32767
static void	check_over_int(char **raw_stack, char **tab, int i)
{
	if ((*tab)[ft_atoi(raw_stack[i]) + 32768] == 1)
	{
		free_tab(raw_stack);
		free(*tab);
		ft_error("Duplicate numbers");
	}
	(*tab)[ft_atoi(raw_stack[i]) + 32768] = 1;
}

void	check_dup_over(char **raw_stack)
{
	char	*tab;
	int		i;

	i = 0;
	tab = ft_calloc(65535, sizeof(char));
	while (raw_stack[i])
	{
		if (ft_atoi(raw_stack[i]) == 32768)
		{
			free_tab(raw_stack);
			free(tab);
			ft_error("A number exceeds the limits of the integers");
		}
		else
			check_over_int(raw_stack, &tab, i);
		i++;
	}
	free(tab);
}

// CHECK IF n1 < n2 < n3 ... < nf
int	check_tri(char **raw_stack)
{
	int		i;
	int		last;

	i = 1;
	last = ft_atoi(raw_stack[0]);
	while (raw_stack[i])
	{
		if (last < ft_atoi(raw_stack[i]))
			last = ft_atoi(raw_stack[i]);
		else
			return (1);
		i++;
	}
	return (0);
}
