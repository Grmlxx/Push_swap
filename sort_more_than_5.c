/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_than_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:26:22 by alamaoui          #+#    #+#             */
/*   Updated: 2024/05/09 09:34:15 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	**copy_list_to_array(t_node *head, int size)
{
	t_node	*current;
	int		i;
	int		**array;

	current = head;
	i = 0;
	array = malloc(sizeof(int *) * size);
	while (current != NULL && i < size)
	{
		array[i] = &(current->value);
		current = current->next;
		i++;
	}
	return (array);
}

int	**sort_array(int **array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (*array[j] > *array[j + 1])
			{
				temp = *array[j];
				*array[j] = *array[j + 1];
				*array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (array);
}

void	update_index(t_node **head, int **array, int size)
{
	t_node	*current;
	int		i;
	int		j;

	current = *head;
	i = 0;
	while (current != NULL && i < size)
	{
		j = 0;
		while (j < size)
		{
			if (current->value == *array[j])
			{
				current->index = j;
				break ;
			}
			j++;
		}
		current = current->next;
		i++;
	}
}

t_node	*copy_stack(t_node *original)
{
	t_node	*copy;
	t_node	*temp;
	t_node	*new_node;

	copy = NULL;
	temp = original;
	while (temp != NULL)
	{
		new_node = (t_node *)malloc(sizeof(t_node));
		if (new_node == NULL)
			exit(1);
		new_node->value = temp->value;
		new_node->next = copy;
		copy = new_node;
		temp = temp->next;
	}
	return (copy);
}

void	sort_more_than_5(t_node **stack_a, t_node **stack_b)
{
	int		range;
	t_node	*copy_stack_a;
	int		**array;
	int		**tab;

	if (ft_lstsize(*stack_a) > 5 && ft_lstsize(*stack_a) <= 100)
		range = 15;
	else
		range = 35;
	copy_stack_a = copy_stack(*stack_a);
	array = copy_list_to_array(copy_stack_a, ft_lstsize(copy_stack_a));
	tab = sort_array(array, ft_lstsize(copy_stack_a));
	update_index(stack_a, tab, ft_lstsize(copy_stack_a));
	push_to_b(stack_a, stack_b, range);
	push_to_a(stack_a, stack_b);
	free(tab);
	free_stack(copy_stack_a);
}
