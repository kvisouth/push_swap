/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:17:42 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/03 15:29:16 by kevisout         ###   ########.fr       */
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
		return (write(2, "Error\n", 6), 0);
	if (!init_stack(&parse, &stack_a, 97) || !init_stack(&parse, &stack_b, 98))
		return (write(2, "Error\n", 6), free(parse.nbrs), 0);
	debug_print_stack(stack_a);
	return (free_stack(&stack_a), free_stack(&stack_b), 1);
}
