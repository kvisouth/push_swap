/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instructions_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevso <kevso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:55:44 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/13 14:56:20 by kevso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* Décale d’une position vers le haut tous les élements de stack_a */
/* Le premier element devient le dernier */
void	ra(t_stack **stack_a, int print)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	last = *stack_a;
	while (last->next)
		last = last->next;
	*stack_a = tmp->next;
	tmp->next = NULL;
	last->next = tmp;
	if (print)
		write(1, "ra\n", 3);
}

/* Décale d’une position vers le haut tous les élements de stack_b */
/* Le premier element devient le dernier */
void	rb(t_stack **stack_b, int print)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	last = *stack_b;
	while (last->next)
		last = last->next;
	*stack_b = tmp->next;
	tmp->next = NULL;
	last->next = tmp;
	if (print)
		write(1, "rb\n", 3);
}

/* ra + rb */
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	write(1, "rr\n", 3);
}
