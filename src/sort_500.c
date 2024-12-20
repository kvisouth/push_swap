/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevso <kevso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:58:52 by kevso             #+#    #+#             */
/*   Updated: 2024/12/20 19:30:13 by kevso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

/* Remonte des elements en haut des piles */
void	get_elems_to_top(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest_node(*a);
	if (cheapest->half == 1 && cheapest->target->half == 1)
	{
		while (*b != cheapest->target && *a != cheapest)
			rr(a, b);
		get_indexes_and_median(*a);
		get_indexes_and_median(*b);
	}
	else if (cheapest->half == 2 && cheapest->target->half == 2)
	{
		while (*b != cheapest->target && *a != cheapest)
			rrr(a, b);
		get_indexes_and_median(*a);
		get_indexes_and_median(*b);
	}
	get_to_top(a, cheapest, 'a');
	get_to_top(b, cheapest->target, 'b');
}

/* rra ou ra jusqu'a que la liste soit triee */
void	rotate_until_sorted(t_stack **a)
{
	t_stack	*smallest;

	smallest = target_the_smallest(*a);
	while (*a != smallest)
	{
		if (smallest->half == 1)
			ra(a, 1);
		else
			rra(a, 1);
	}
}

void	sort_turk(t_stack **a, t_stack **b)
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
	rotate_until_sorted(a);
}

/*

Comment fonctionne le turk sort :

1. On fait 2x pb, peu importe les valeurs, on s'en fout
	C'est pour avoir 2 elements a cibler depuis la stack a

2. Tant que la stack 'a' a plus de 3 elements :
	a. On indexe les elements de 'a' et 'b', et on determine leurs medianes
	b. On determine une cible pour chaque element de 'a' dans 'b'
		Une cible c'est "Le plus proche en dessous" dans 'b'. (en gros)
	c. On calcule le nombre d'operations necessaires pour chaque element
		de 'a' pour atteindre sa cible.
	d. On determine l'element le moins couteux suite aux calculs precedents
	e. On fait en sorte que l'element le moins couteux soit en haut de 'a' et
		que sa cible soit en haut de 'b'
	f. On push l'element le moins couteux de 'a' vers 'b', et ca fait que
		l'element le moins couteux de 'a' a bien rejoins sa cible dans 'b'

3. On trie les 3 derniers elements de 'a' avec sort_3

4. On fait un peu comme quand on a vider 'a' dans 'b', mais dans l'autre sens.
	Tant que la stack 'b' n'est pas vide :
	a. On indexe les elements de 'a' et 'b', et on determine leurs medianes
	b. On determine une cible pour chaque element de 'b' dans 'a'
		Cette fois, la cible ne sera pas le plus proche en dessous, mais le
		plus proche au dessus.
	c. On fait tourner 'a' pour que la cible de l'element au sommet de 'b'
		soit en haut de 'a', en jouant avec rra et ra selon la mediane.
	d. On push l'element au sommet de 'b' dans 'a'

5. On fait tourner 'a' jusqu'a ce qu'il soit trie, dans un sens ou dans l'autre
	selon ou se trouve le plus petit element par rapport a la mediane.

*/