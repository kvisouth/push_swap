/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:43:21 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/03 17:50:23 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	(void)stack_a;
	(void)stack_b;
	if (size == 2)
		printf("algo 2\n");
	else if (size == 3)
		printf("algo 3\n");
	else if (size == 4)
		printf("algo 4\n");
	else if (size == 5)
		printf("algo 5\n");
	else if (size > 5 && size <= 500)
		printf("algo 5+\n");
	return (1);
}
