/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instructions_swap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevso <kevso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:52:10 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/13 14:57:18 by kevso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* Intervertit les 2 premiers elements de stack_a */
void	sa(t_stack **stack_a, int print)
{
	t_stack	*tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	if (print)
		write(1, "sa\n", 3);
}

/* Intervertit les 2 premiers elements de stack_b */
void	sb(t_stack **stack_b, int print)
{
	t_stack	*tmp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	if (print)
		write(1, "sb\n", 3);
}

/* sa + sb */
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	write(1, "ss\n", 3);
}
