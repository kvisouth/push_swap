/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevso <kevso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:58:31 by kevso             #+#    #+#             */
/*   Updated: 2024/12/13 15:21:32 by kevso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* Tri un stack de 3 éléments (HARDCODED) */
void	sort_3(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->nb;
	second = (*stack)->next->nb;
	third = (*stack)->next->next->nb;
	if (first > second && second < third && first < third)
		sa(stack, 1);
	else if (first > second && second > third)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (first > second && second < third && first > third)
		ra(stack, 1);
	else if (first < second && second > third && first < third)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (first < second && second > third && first > third)
		rra(stack, 1);
}
