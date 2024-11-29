/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:00:47 by kevisout          #+#    #+#             */
/*   Updated: 2024/11/29 19:01:41 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long	ft_atol(const char *str)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	return (nbr * sign);
}

/* Range les nombres presents dans str dans un tableau d'entiers */
long	*get_nbrs(char *str, int count)
{
	long	*nbrs;
	int		i;
	int		j;

	nbrs = ft_calloc(count, sizeof(long));
	if (!nbrs)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && (ft_isdigit(str[i]) || (str[i] == '-')))
		{
			nbrs[j] = ft_atol(&str[i]);
			j++;
		}
		while (str[i] && (ft_isdigit(str[i]) || (str[i] == '-')))
			i++;
	}
	return (nbrs);
}

/* Check si il n'y a pas de doublons dans le tableau */
int	check_duplicates(long *nbrs)
{
	int	i;
	int	j;

	i = 0;
	while (nbrs[i])
	{
		j = i + 1;
		while (nbrs[j])
		{
			if (nbrs[i] == nbrs[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/* Check si il y a des nombres plus elevees que INTMAX ou inferieur a INTMIN */
int	check_overflows(long *nbrs)
{
	int	i;

	i = 0;
	while (nbrs[i])
	{
		if (nbrs[i] > 2147483647 || nbrs[i] < -2147483648)
			return (0);
		i++;
	}
	return (1);
}
