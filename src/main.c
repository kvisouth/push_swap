/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:17:42 by kevisout          #+#    #+#             */
/*   Updated: 2024/11/30 11:25:49 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	char	*args;
	long	*nbrs;
	int		cpt;

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
	return (free(nbrs), 1);
}
