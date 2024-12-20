/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_500.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevso <kevso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:58:52 by kevso             #+#    #+#             */
/*   Updated: 2024/12/20 16:45:23 by kevso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* Retourne la taille d'une stack */
int	get_stack_size(t_stack *stack)
{
	t_stack	*tmp;
	int		size;

	size = 0;
	tmp = stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

/* Indexe les éléments de la stack et determine dans quel moitiee ils sont */
void	get_indexes_and_median(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	if (!tmp)
		return ;
	while (tmp)
	{
		tmp->index = i;
		if (i <= get_stack_size(stack) / 2)
			tmp->half = 1;
		else
			tmp->half = 2;
		tmp = tmp->next;
		i++;
	}
}

/* Retourne un ptr sur le plus grand élément (nb) de la stack */
t_stack	*target_the_biggest(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*biggest;
	int		max;

	tmp = stack;
	biggest = stack;
	max = INT_MIN;
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		if (tmp->nb > max)
		{
			max = tmp->nb;
			biggest = tmp;
		}
		tmp = tmp->next;
	}
	return (biggest);
}

/* Retourne un ptr sur le plus petit élément (nb) de la stack */
t_stack	*target_the_smallest(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*smallest;
	int		min;

	tmp = stack;
	smallest = stack;
	min = INT_MAX;
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		if (tmp->nb < min)
		{
			min = tmp->nb;
			smallest = tmp;
		}
		tmp = tmp->next;
	}
	return (smallest);
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
	if (!tmp_a)
		return ;
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

/* Retourne le ptr sur l'element le moins couteux */
t_stack	*get_cheapest_node(t_stack *a)
{
	t_stack	*tmp_a;

	tmp_a = a;
	while (tmp_a)
	{
		if (tmp_a->cheapest)
			return (tmp_a);
		tmp_a = tmp_a->next;
	}
	return (NULL);
}

/* Remonte l'element le moins couteux en haut de la stack */
void	get_to_top(t_stack **stack, t_stack *node_to_move, char stack_name)
{
	while (*stack != node_to_move)
	{
		if (stack_name == 'a')
		{
			if (node_to_move->half == 1)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (stack_name == 'b')
		{
			if (node_to_move->half == 1)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}

/* rra ou ra jusqu'a que a et b soient dans la meme moitie (Haute)*/
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rr(a, b);
	get_indexes_and_median(*a);
	get_indexes_and_median(*b);
}

/* Performe un rrr si a et b sont dans la meme moitie (Basse)*/
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rrr(a, b);
	get_indexes_and_median(*a);
	get_indexes_and_median(*b);
}

/* Met les elements les moins couteux en haut de a et/ou b */
void	get_elems_to_top(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest_node(*a);
	if (cheapest->half == 1 && cheapest->target->half == 1)
		rotate_both(a, b, cheapest);
	else if (cheapest->half == 2 && cheapest->target->half == 2)
		reverse_rotate_both(a, b, cheapest);
	get_to_top(a, cheapest, 'a');
	get_to_top(b, cheapest->target, 'b');
}

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

/* rra ou ra jusqu'a que la liste soit triee */
void	rotate_until_sorted(t_stack *a)
{
	t_stack	*smallest;

	get_indexes_and_median(a);
	smallest = target_the_smallest(a);
	while (!is_sorted(a))
	{
		if (smallest->half == 1)
			ra(&a, 1);
		else
			rra(&a, 1);
	}
}

void	sort_500(t_stack **a, t_stack **b)
{
	pb(a, b);
	pb(a, b);
	while (get_stack_size(*a) > 3)
	{
		get_indexes_and_median(*a);
		get_indexes_and_median(*b);
		get_targets_in_b(*a, *b);
		get_cost_in_a(*a, *b);
		get_cheapest(*a);
		get_elems_to_top(a, b);
		pb(a, b);
	}
	sort_3(a);
	while (get_stack_size(*b) > 0)
	{
		get_indexes_and_median(*a);
		get_indexes_and_median(*b);
		get_targets_in_a(*a, *b);
		get_to_top(a, (*b)->target, 'a');
		pa(a, b);
	}
	rotate_until_sorted(*a);
}
