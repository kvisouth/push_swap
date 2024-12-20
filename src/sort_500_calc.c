/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevso <kevso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:53:13 by kevso             #+#    #+#             */
/*   Updated: 2024/12/20 18:59:59 by kevso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* Attribue une target dans b à chaque élément de a */
void	get_targets_in_b(t_stack *a, t_stack *b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	t_stack	*target_node;
	int		target_value;

	tmp_a = a;
	while (tmp_a)
	{
		target_value = INT_MIN;
		tmp_b = b;
		while (tmp_b)
		{
			if (tmp_b->nb < tmp_a->nb && tmp_b->nb > target_value)
			{
				target_value = tmp_b->nb;
				target_node = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (target_value == INT_MIN)
			tmp_a->target = target_the_biggest(b);
		else
			tmp_a->target = target_node;
		tmp_a = tmp_a->next;
	}
}

/* Pareil que get_targets_in_b mais dans l'autre sens */
void	get_targets_in_a(t_stack *a, t_stack *b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	t_stack	*target_node;
	int		target_value;

	tmp_b = b;
	while (tmp_b)
	{
		target_value = INT_MAX;
		tmp_a = a;
		while (tmp_a)
		{
			if (tmp_a->nb > tmp_b->nb && tmp_a->nb < target_value)
			{
				target_value = tmp_a->nb;
				target_node = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (target_value == INT_MAX)
			tmp_b->target = target_the_smallest(a);
		else
			tmp_b->target = target_node;
		tmp_b = tmp_b->next;
	}
}

/* Determine combien d'OP il faut pour mettre un element au sommet de a pour */
/* qu'il atteigne sa target dans b (on peut rb ou rrb aussi) */
void	get_cost_in_a(t_stack *a, t_stack *b)
{
	t_stack	*tmp_a;

	tmp_a = a;
	while (tmp_a)
	{
		tmp_a->cost = tmp_a->index;
		if (tmp_a->half == 2)
			tmp_a->cost = get_stack_size(a) - tmp_a->index;
		if (tmp_a->target->half == 1)
			tmp_a->cost += tmp_a->target->index;
		else
			tmp_a->cost += get_stack_size(b) - tmp_a->target->index;
		tmp_a = tmp_a->next;
	}
}

/* Determine l'element le moins couteux, grace aux calculs de get_cost_in_a */
void	get_cheapest(t_stack *a)
{
	t_stack	*tmp_a;
	t_stack	*addr_of_cheapest_node;
	int		cheapest;

	tmp_a = a;
	cheapest = INT_MAX;
	while (tmp_a)
	{
		if (tmp_a->cost < cheapest)
		{
			cheapest = tmp_a->cost;
			addr_of_cheapest_node = tmp_a;
		}
		tmp_a = tmp_a->next;
	}
	addr_of_cheapest_node->cheapest = 1;
}
