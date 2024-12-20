/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevso <kevso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:55:07 by kevso             #+#    #+#             */
/*   Updated: 2024/12/20 18:59:25 by kevso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

/* Retourne l'element le moins couteux */
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
