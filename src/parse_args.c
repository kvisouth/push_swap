/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:00:56 by kevisout          #+#    #+#             */
/*   Updated: 2024/11/29 19:05:44 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* Check si args ne contient que des digits, des whitespaces ou des '-' */
int	check_only_numeric(char *args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!ft_isdigit(args[i]) && args[i] != ' '
			&& !(args[i] == '-' && ((i == 0 && ft_isdigit(args[i + 1]))
					|| (i > 0 && args[i - 1] == ' '
						&& ft_isdigit(args[i + 1])))))
			return (0);
		i++;
	}
	return (1);
}

/* Compte le nombre de nombres dans args */
int	count_nbrs(char *args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (args[i])
	{
		while (args[i] && args[i] == ' ')
			i++;
		if (args[i] && (ft_isdigit(args[i]) || (args[i] == '-')))
			count++;
		while (args[i] && (ft_isdigit(args[i]) || (args[i] == '-')))
			i++;
	}
	return (count);
}

/* Le parsing check si on a que des nombres, pas de doublons et pas de INTMAX */
int	parse_args(char *args)
{
	int		count;
	long	*nbrs;

	count = 0;
	nbrs = NULL;
	if (!check_only_numeric(args))
		return (0);
	count = count_nbrs(args);
	nbrs = get_nbrs(args, count);
	if (!check_duplicates(nbrs))
		return (0);
	if (!check_overflows(nbrs))
		return (0);
	return (1);
}
