/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:17:57 by kevisout          #+#    #+#             */
/*   Updated: 2024/11/30 11:26:02 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "../libft/libft.h"\

/* Parsing */
char	*join_args(int ac, char **av);
long	*get_nbrs(char *str, int count);
int     count_nbrs(char *args);
int		check_overflows(long *nbrs, int count);
int		check_duplicates(long *nbrs, int count);
int		parse_args(char *args);

#endif