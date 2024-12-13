/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instructions_reverse.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevso <kevso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:56:11 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/13 14:54:53 by kevso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* Décale d’une position vers le bas tous les élements de stack_a */
/* Le dernier element devient le premier */
void	rra(t_stack **stack_a, int print)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	if (print)
		write(1, "rra\n", 4);
}

/* Décale d’une position vers le bas tous les élements de stack_b */
/* Le dernier element devient le premier */
void	rrb(t_stack **stack_b, int print)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	if (print)
		write(1, "rrb\n", 4);
}

/* rra + rrb */
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	write(1, "rrr\n", 4);
}
