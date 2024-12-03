/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:17:42 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/03 14:04:49 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	debug_print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("%d\n", tmp->nb);
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	char	*args;
	long	*nbrs;
	int		cpt;
	t_stack	*stack;

	args = join_args(ac, av);
	if (!args)
		return (0);
	if (!parse_args(args))
		return (free(args), 0);
	cpt = count_nbrs(args);
	nbrs = get_nbrs(args, cpt);
	free(args);
	if (!nbrs)
		return (0);
	if (!init_stack(nbrs, cpt, &stack))
		return (free(nbrs), 0);
	debug_print_stack(stack);
	free(nbrs);
	return (1);
}
