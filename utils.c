/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:53:20 by alamaoui          #+#    #+#             */
/*   Updated: 2024/05/15 17:16:18 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
		y = 0;
		while (av[i][y] && av[i][y] == ' ')
			y++;
		if (av[i][y] == '\0')
			bye_bye();
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

static void	fuck_off(char *args, char **tokens, t_node *stack_a)
{
	free_memory(args, tokens);
	free_stack(stack_a);
	bye_bye();
}

static void	list_order(t_node **stack_a, t_node *new_list)
{
	t_node	*temp;

	if (*stack_a == NULL)
		*stack_a = new_list;
	else
	{
		temp = *stack_a;
		while (temp->next)
			temp = temp->next;
		temp->next = new_list;
	}
}

t_node	*read_data(t_node *stack_a, char **av, char **tokens, char *args)
{
	static int	x;
	t_node		*new_list;
	long		num;

	args = args_joiner(av);
	tokens = ft_split(args, ' ');
	while (tokens[x])
	{
		if (((tokens[x][0] == '-' || tokens[x][0] == '+')
				&& tokens[x][1] == '\0') || tokens[x][0] == '\t')
			fuck_off(args, tokens, stack_a);
		num = ft_atoi(tokens[x], num);
		is_num_oflow(num, stack_a, args, tokens);
		new_list = create_node(num);
		list_order(&stack_a, new_list);
		x++;
	}
	return (free_memory(args, tokens), stack_a);
}
