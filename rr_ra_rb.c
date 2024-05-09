/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_ra_rb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:01:36 by alamaoui          #+#    #+#             */
/*   Updated: 2024/05/09 18:07:58 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rr(t_node *stack_a, t_node *stack_b, int flag)
{
	if ((stack_a && stack_a->next) && (stack_b && stack_b->next))
	{
		ra(&stack_a, 0);
		rb(&stack_b, 0);
	}
	if (flag == 1)
		write(1, "rr\n", 3);
}

void	ra(t_node **stack_a, int flag)
{
	t_node	*first;
	t_node	*last;

	if (*stack_a && (*stack_a)->next)
	{
		first = *stack_a;
		*stack_a = (*stack_a)->next;
		first->next = NULL;
		last = *stack_a;
		while (last->next)
			last = last->next;
		last->next = first;
		if (flag == 1)
			write(1, "ra\n", 3);
	}
}

void	rb(t_node **stack_b, int flag)
{
	t_node	*first;
	t_node	*last;

	if (*stack_b && (*stack_b)->next)
	{
		first = *stack_b;
		*stack_b = (*stack_b)->next;
		first->next = NULL;
		last = *stack_b;
		while (last->next)
			last = last->next;
		last->next = first;
		if (flag == 1)
			write(1, "rb\n", 3);
	}
}
