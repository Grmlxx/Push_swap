/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_sa_sb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:01:33 by alamaoui          #+#    #+#             */
/*   Updated: 2024/05/12 23:16:11 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ss(t_node *stack_a, t_node *stack_b, int flag)
{
	if ((stack_a && stack_a->next) && (stack_b && stack_b->next))
	{
		sa(stack_a, 0);
		sb(stack_b, 0);
	}
	if (flag == 1)
		write(1, "ss\n", 3);
}

void	sa(t_node *stack_a, int flag)
{
	int	temp;

	if (stack_a && stack_a->next)
	{
		temp = stack_a->value;
		stack_a->value = stack_a->next->value;
		stack_a->next->value = temp;
		if (flag == 1)
			write(1, "sa\n", 3);
	}
}

void	sb(t_node *stack_b, int flag)
{
	int	temp;

	if (stack_b && stack_b->next)
	{
		temp = stack_b->value;
		stack_b->value = stack_b->next->value;
		stack_b->next->value = temp;
	}
	if (flag == 1)
		write(1, "sb\n", 3);
}

int	smallest(t_node *stack_a)
{
	t_node	*current;
	int		smallest;

	current = stack_a;
	smallest = current->value;
	while (current != NULL)
	{
		if (current->value < smallest)
			smallest = current->value;
		current = current->next;
	}
	return (smallest);
}

int	smallest_index(t_node *stack_a, int small)
{
	t_node	*current;
	int		index;

	current = stack_a;
	index = 0;
	while (current != NULL)
	{
		if (small == current->value)
			return (index);
		index++;
		current = current->next;
	}
	return (index);
}
