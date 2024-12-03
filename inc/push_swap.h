/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:17:57 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/03 17:50:36 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdint.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}	t_stack;

typedef struct s_parse
{
	int		count;
	long	*nbrs;
	char	*args;
}	t_parse;

/* Parsing */
char	*join_args(int ac, char **av);
long	*get_nbrs(char *str, int count);
int		count_nbrs(char *args);
int		check_overflows(long *nbrs, int count);
int		check_duplicates(long *nbrs, int count);
int		parse_args(char *args);
int		parsing(int ac, char **av, t_parse *parse);

/* Sorting */
int		sort(t_stack **stack_a, t_stack **stack_b, int size);

/* Init */
int		init_stack(t_parse *parse, t_stack **stack, char c);
int		fill_stack(t_stack **stack, long *nbrs, int count);

#endif