/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_rra_rrb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:01:30 by alamaoui          #+#    #+#             */
/*   Updated: 2024/05/09 10:03:29 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rrr(t_node *stack_a, t_node *stack_b, int flag)
{
	rra(&stack_a, 0);
	rrb(&stack_b, 0);
	if (flag == 1)
		write(1, "rrr\n", 4);
}

void	rra(t_node **stack_a, int flag)
{
	t_node	*last;
	t_node	*second_to_last;

	if (*stack_a && (*stack_a)->next)
	{
		last = *stack_a;
		while (last->next)
		{
			second_to_last = last;
			last = last->next;
		}
		second_to_last->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
		if (flag == 1)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_node **stack_b, int flag)
{
	t_node	*last;
	t_node	*second_to_last;

	if (*stack_b && (*stack_b)->next)
	{
		last = *stack_b;
		while (last->next)
		{
			second_to_last = last;
			last = last->next;
		}
		second_to_last->next = NULL;
		last->next = *stack_b;
		*stack_b = last;
		if (flag == 1)
			write(1, "rrb\n", 4);
	}
}
