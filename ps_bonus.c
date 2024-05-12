/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 23:53:08 by alamaoui          #+#    #+#             */
/*   Updated: 2024/05/09 19:28:40 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	not_an_action(char *line, t_node **stack_a, t_node **stack_b)
{
	free_stack(*stack_a);
	free_stack(*stack_b);
	free(line);
	bye_bye();
}

void	checker(char *line, t_node **stack_a, t_node **stack_b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(*stack_a, 0);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(*stack_b, 0);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(*stack_a, *stack_b, 0);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(stack_a, 0);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(stack_b, 0);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(*stack_a, *stack_b, 0);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(stack_a, 0);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(stack_b, 0);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(*stack_a, *stack_b, 0);
	else
		not_an_action(line, stack_a, stack_b);
}

void	reader(t_node **stack_a, t_node **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		checker(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (ft_lstsize(*stack_b) != 0)
	{
		write(1, "KO\n", 3);
		return ;
	}
	if (is_sorted(*stack_a) == 1 && ft_lstsize(*stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**tokens;
	char	*args;

	stack_a = NULL;
	stack_b = NULL;
	tokens = NULL;
	args = NULL;
	if (ac < 2)
		return (0);
	stack_a = read_data(stack_a, av, tokens, args);
	check_duplicates(stack_a);
	reader(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
