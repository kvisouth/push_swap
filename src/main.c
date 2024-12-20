/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevso <kevso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:17:42 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/20 18:31:01 by kevso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	debug_print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	printf("\n");
	while (tmp)
	{
		printf("%d", tmp->nb);
		if (tmp->next)
			printf(" , ");
		tmp = tmp->next;
	}
}

/* Free and delete list */
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_parse	parse;

	stack_a = NULL;
	stack_b = NULL;
	if (!parsing(ac, av, &parse))
		return (write(2, "Error\n", 6), 1);
	if (!init_stack(&parse, &stack_a, 97))
		return (write(2, "Error\n", 6), free(parse.nbrs), 1);
	free(parse.nbrs);
	if (!sort(&stack_a, &stack_b, parse.count))
		return (write(2, "Error\n", 6), 1);
	free_stack(&stack_a);
	return (0);
}
