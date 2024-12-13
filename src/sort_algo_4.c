/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevso <kevso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:58:38 by kevso             #+#    #+#             */
/*   Updated: 2024/12/13 17:14:52 by kevso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* Trie un stack de 4 éléments */
void	sort_4(t_stack **stack_a, t_stack **stack_b)
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
	sort_3(stack_a);
	pa(stack_a, stack_b);
}
