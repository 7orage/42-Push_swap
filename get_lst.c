/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:23:48 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/10 16:43:12 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
// FREE THE LIST
void	lst_free(t_data *img)
{
	t_col	*tmp;

	while (img->map.collectibles)
	{
		tmp = img->map.collectibles->next;
		free(img->map.collectibles);
		img->map.collectibles = tmp;
	}
}

// REMOVE A COLLECTIBLE FROM THE LISTE, SET AS "NON ACCESSIBLE"
void	lst_remove_col(t_col **liste, int x, int y)
{
	t_col	*ptr;
	t_col	*tmp;

	if (!liste || !*liste)
		return ;
	ptr = *liste;
	if (ptr->x == x && ptr->y == y)
	{
		if (ptr->next != NULL)
			*liste = ptr->next;
		else
			*liste = NULL;
		return (free(ptr));
	}
	while (ptr->next != NULL)
	{
		if (ptr->next->x == x && ptr->next->y == y)
		{
			tmp = ptr->next;
			ptr->next = tmp->next;
			free(tmp);
			return ;
		}
		ptr = ptr->next;
	}
}

// CHECK IF THE COLLECTIBLE IS ALREADY WON
int	lst_verif_col(t_col **liste, int x, int y)
{
	t_col	*ptr;

	if (!*liste)
		return (0);
	ptr = *liste;
	while (ptr->next != NULL)
	{
		if (ptr->x == x && ptr->y == y)
			return (1);
		ptr = ptr->next;
	}
	if (ptr->x == x && ptr->y == y)
		return (1);
	return (0);
}*/

// ADD A NEW COLLECTIBLE TO THE LISTE
void	lst_new_val(t_stack **stack_a, int value)
{
	t_stack	*new;
	t_stack	*ptr;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->value = value;
	new->index = -1;
	new->next = NULL;
	if (!*stack_a)
		*stack_a = new;
	else
	{
		ptr = *stack_a;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
}

void	set_index(t_stack **stack_a, int i)
{
	t_stack	*high;
	t_stack *tp;

	while (i--)
	{
		high = NULL;
		tp = *stack_a;
		while (tp)
		{
			if (tp->index < 0 && (high == NULL || tp->value > high->value))
				high = tp;
			tp = tp->next;
		}
		if (high)
			high->index = i;
	}
}

// INIT THE COLLECTIBLE LISTE
void	lst_get_list(t_stack **stack_a, char **raw_stack)
{
	int					i;

	i = 0;
	while (raw_stack[i])
	{
		lst_new_val(stack_a, ft_atoi(raw_stack[i]));
		i++;
	}
	set_index(stack_a, i);
}