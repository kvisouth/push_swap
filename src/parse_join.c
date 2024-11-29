/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:06:40 by kevisout          #+#    #+#             */
/*   Updated: 2024/11/29 16:27:29 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* count_args_len retourne additionne la longueur de tout les arguments */
int	count_args_len(int ac, char **av)
{
	int		i;
	int		len;

	i = 1;
	len = 0;
	while (i < ac)
	{
		len += ft_strlen(av[i]);
		i++;
	}
	return (len + 1);
}

/* join_args va creer une seule et unique string a partir des arguments */
char	*join_args(int ac, char **av)
{
	char	*str;
	int		i;

	str = ft_calloc((count_args_len(ac, av) + ac + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		ft_strlcat(str, av[i], count_args_len(ac, av) + ac + 1);
		if (i < ac - 1)
			ft_strlcat(str, " ", count_args_len(ac, av) + ac + 1);
		i++;
	}
	return (str);
}
