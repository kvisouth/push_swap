/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevso <kevso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:43:21 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/20 18:46:17 by kevso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* Trouve la position du plus petit nombre */
int	find_smallest_pos(t_stack *stack)
{
	t_stack	*tmp;
	int		smallest;
	int		pos;
	int		i;

	smallest = stack->nb;
	pos = 0;
	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->nb < smallest)
		{
			smallest = tmp->nb;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

/* Retourne 1 si les entiers dans stack sont triees (croissant), 0 sinon */
int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* Trie stack_a */
int	sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 1 || is_sorted(*stack_a))
		return (1);
	else if (size == 2)
		sort_2(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else
		sort_turk(stack_a, stack_b);
	return (1);
}
