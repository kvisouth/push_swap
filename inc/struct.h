/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:35:46 by kevso             #+#    #+#             */
/*   Updated: 2024/12/21 17:31:40 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/* Structure utile pour le parsing */
typedef struct s_parse
{
	int		count;
	long	*nbrs;
	char	*args;
}	t_parse;

/* Structure d'une pile (A et B) */
typedef struct s_stack
{
	int				nb;
	int				index;
	int				cost;
	int				half;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

#endif

/*

nb = nombre de la pile (Ceux que l'utilisateur rentre)
index = index de l'élément dans la pile
cost = cout pour mettre l'élément au sommet de la pile
half = moitié de la pile (moitié 1 ou 2)
cheapest = élément le moins couteux (Oui ou Non)
target = cible de l'élément dans l'autre pile
next = élément suivant de la pile

*/