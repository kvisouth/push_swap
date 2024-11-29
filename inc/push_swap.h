/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:17:57 by kevisout          #+#    #+#             */
/*   Updated: 2024/11/29 19:07:08 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

/* Parsing */
char	*join_args(int ac, char **av);
long	*get_nbrs(char *str, int count);
int		check_overflows(long *nbrs);
int		check_duplicates(long *nbrs);
int		parse_args(char *args);

#endif