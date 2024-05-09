/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:01:48 by alamaoui          #+#    #+#             */
/*   Updated: 2024/05/09 10:01:53 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pa(t_node **stack_a, t_node **stack_b, int flag)
{
	t_node	*temp;

	if (*stack_b)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = *stack_a;
		*stack_a = temp;
		if (flag == 1)
			write(1, "pa\n", 3);
	}
}

void	pb(t_node **stack_a, t_node **stack_b, int flag)
{
	t_node	*temp;

	if (*stack_a)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = *stack_b;
		*stack_b = temp;
		if (flag == 1)
			write(1, "pb\n", 3);
	}
}
