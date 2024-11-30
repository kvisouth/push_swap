/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:17:42 by kevisout          #+#    #+#             */
/*   Updated: 2024/11/30 11:01:09 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*args;

	args = join_args(ac, av);
	if (!args)
		return (1);
	if (!parse_args(args))
		return (free(args), 1);
	free(args);
	return (0);
}
