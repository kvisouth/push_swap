/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:03:08 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/03 15:03:13 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* Uses all the parsing functions at once */
int	parsing(int ac, char **av, t_parse *parse)
{
	if (ac <= 1)
		return (0);
	parse->args = join_args(ac, av);
	if (!parse->args)
		return (0);
	if (!parse_args(parse->args))
		return (free(parse->args), 0);
	parse->count = count_nbrs(parse->args);
	parse->nbrs = get_nbrs(parse->args, parse->count);
	free(parse->args);
	if (!parse->nbrs)
		return (0);
	return (1);
}
