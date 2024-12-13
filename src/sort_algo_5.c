/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevso <kevso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:58:44 by kevso             #+#    #+#             */
/*   Updated: 2024/12/13 17:28:12 by kevso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_first_smallest_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;

	pos = find_smallest_pos(*stack_a);
	if (pos == 1)
		ra(stack_a, 1);
	else if (pos == 2)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (pos == 3)
	{
		rra(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (pos == 4)
		rra(stack_a, 1);
	pb(stack_a, stack_b);
}

void	push_second_smallest_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;
	
	pos = find_smallest_pos(*stack_a);
	if (pos == 1)
		ra(stack_a, 1);
	else if (pos == 2)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (pos == 3)
		rra(stack_a, 1);
	pb(stack_a, stack_b);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	push_first_smallest_to_b(stack_a, stack_b);
	push_second_smallest_to_b(stack_a, stack_b);
	sort_3(stack_a);
	if ((*stack_b)->nb < (*stack_b)->next->nb)
		sb(stack_b, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

