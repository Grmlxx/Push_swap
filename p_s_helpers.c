/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:01:56 by alamaoui          #+#    #+#             */
/*   Updated: 2024/05/09 12:54:57 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	bye_bye(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_node *stack)
{
	t_node	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	check_duplicates(t_node *stack)
{
	t_node	*current;
	t_node	*temp;

	current = stack;
	while (current)
	{
		temp = current->next;
		while (temp)
		{
			if (current->value == temp->value)
			{
				free_stack(stack);
				bye_bye();
			}
			temp = temp->next;
		}
		current = current->next;
	}
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->value = value;
	node->next = NULL;
	return (node);
}

int	is_sorted(t_node *stack_a)
{
	t_node	*tmp;

	tmp = stack_a;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
