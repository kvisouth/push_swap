/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:33:56 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/03 14:57:08 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* Range notre tableau d'entiers dans une liste chainees d'entiers */
int	fill_stack(t_stack **stack, long *nbrs, int count)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack;
	while (i < count)
	{
		tmp->nb = nbrs[i];
		tmp = tmp->next;
		i++;
	}
	return (1);
}

/* Initialise notre liste chainees d'entiers avec des 0 */
int	init_stack(long *nbrs, int count, t_stack **stack, char c)
{
	int		i;
	t_stack	*new;

	i = 0;
	while (i < count)
	{
		new = ft_calloc(1, sizeof(t_stack));
		if (!new)
			return (0);
		new->nb = 0;
		new->next = *stack;
		*stack = new;
		i++;
	}
	if (c == 'a')
		return (fill_stack(stack, nbrs, count));
	return (1);
}
