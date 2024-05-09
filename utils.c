/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:53:20 by alamaoui          #+#    #+#             */
/*   Updated: 2024/05/09 17:56:27 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

char	*args_joiner(char **av)
{
	int		i;
	char	*args;
	int		y;

	y = 0;
	i = 1;
	args = NULL;
	while (av[i])
	{
		while (av[i][y] && av[i][y] == ' ')
			y++;
		if (av[i][y] == '\0')
			bye_bye();
		if (av[i][0] == '\0' || (((av[i][0] == '-' || av[i][0] == '+')
					&& av[i][1] == '\0')))
		{
			free(args);
			bye_bye();
		}
		args = ft_strjoin(args, av[i]);
		args = ft_strjoin(args, " ");
		i++;
	}
	return (args);
}

void	is_num_oflow(long num, t_node *stack_a, char *args, char **tokens)
{
	if (num == 2147483649)
	{
		free_stack(stack_a);
		free_memory(args, tokens);
		bye_bye();
	}
}

t_node	*read_data(t_node *stack_a, char **av, char **tokens, char *args)
{
	static int	x;
	t_node		*last_node;
	t_node		*new_list;
	long		num;

	args = args_joiner(av);
	tokens = ft_split(args, ' ');
	while (tokens[x])
	{
		num = ft_atoi(tokens[x], num);
		is_num_oflow(num, stack_a, args, tokens);
		new_list = create_node(num);
		if (stack_a == NULL)
		{
			stack_a = new_list;
			last_node = new_list;
		}
		else
		{
			last_node->next = new_list;
			last_node = new_list;
		}
		x++;
	}
	return (free_memory(args, tokens), stack_a);
}
