/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevso <kevso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:17:57 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/20 17:21:40 by kevso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include "../libft/libft.h"

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
int		is_sorted(t_stack *stack);
int		sort(t_stack **stack_a, t_stack **stack_b, int size);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a, int print);
void	sb(t_stack **stack_b, int print);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a, int print);
void	rb(t_stack **stack_b, int print);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a, int print);
void	rrb(t_stack **stack_b, int print);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/* Sort algo */
void	sort_2(t_stack **stack);
void	sort_3(t_stack **stack);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);
void	sort_500(t_stack **stack_a, t_stack **stack_b);

/* Init */
void	free_stack(t_stack **stack);
int		init_stack(t_parse *parse, t_stack **stack, char c);
int		find_smallest_pos(t_stack *stack);
int		fill_stack(t_stack **stack, long *nbrs, int count);

#endif