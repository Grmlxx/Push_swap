/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_than_5_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 23:15:38 by alamaoui          #+#    #+#             */
/*   Updated: 2024/05/09 10:06:52 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_memory(char *args, char **tokens)
{
	int	x;

	free(args);
	x = 0;
	while (tokens[x])
	{
		free(tokens[x]);
		x++;
	}
	free(tokens);
}

int	bigger(t_node *stack_a)
{
	t_node	*current;
	int		bigger;

	current = stack_a;
	bigger = current->value;
	while (current != NULL)
	{
		if (current->value > bigger)
			bigger = current->value;
		current = current->next;
	}
	return (bigger);
}

int	bigger_index(t_node *stack_b, int big)
{
	t_node	*current;
	int		index;

	current = stack_b;
	index = 0;
	while (current != NULL)
	{
		if (big == current->value)
			return (index);
		index++;
		current = current->next;
	}
	return (index);
}

void	push_to_b(t_node **stack_a, t_node **stack_b, int range)
{
	while (ft_lstsize(*stack_a) != 0)
	{
		if ((*stack_a)->index < ft_lstsize(*stack_b))
		{
			pb(stack_a, stack_b, 1);
			rb(stack_b, 1);
		}
		else if ((*stack_a)->index <= (ft_lstsize(*stack_b) + range))
			pb(stack_a, stack_b, 1);
		else
			ra(stack_a, 1);
	}
}

void	push_to_a(t_node **stack_a, t_node **stack_b)
{
	int	big;
	int	big_index;

	while (ft_lstsize(*stack_b) != 0)
	{
		big = bigger(*stack_b);
		big_index = bigger_index(*stack_b, big);
		while ((*stack_b)->value != big)
		{
			if (big_index < ft_lstsize(*stack_b) / 2)
				rb(stack_b, 1);
			else
				rrb(stack_b, 1);
		}
		pa(stack_a, stack_b, 1);
	}
}
