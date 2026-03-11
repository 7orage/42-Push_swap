/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:52:20 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/11 15:27:02 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "includes/ft_printf/ft_printf.h"
# include "includes/libft/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

char	**get_stack(char **stack_f, char **argv);

void	ft_error(char *s);
void	free_tab(char **tab);
void	lst_get_list(t_stack **stack_a, char **raw_stack);
void	lst_new_val(t_stack **stack_a, int value);
void	lst_free(t_stack *stack);

void	check_num(char *stack);
void	check_dup_over(char **raw_stack);

int		check_tri(char **raw_stack);
int		get_stack_size(t_stack *stack);

void	radix_sort_test(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack_a);
//void	rotate_b(t_stack **stack_b);
//void	swap_a(t_stack *stack_a);
//void	swap_b(t_stack *stack_b);
//void	ss(t_stack *stack_a, t_stack *stack_b);
//void	rr(t_stack *stack_a, t_stack *stack_b);
//void	rra(t_stack *stack_a);
//void	rrb(t_stack *stack_b);
//void	rrr(t_stack *stack_a, t_stack *stack_b);

#endif