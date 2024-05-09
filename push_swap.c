/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:01:42 by alamaoui          #+#    #+#             */
/*   Updated: 2024/05/09 10:48:22 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sorter(t_node **stack_a, t_node **stack_b)
{
	int	lst_len;

	lst_len = ft_lstsize(*stack_a);
	if (is_sorted(*stack_a))
	{
		free_stack(*stack_a);
		exit(0);
	}
	else if (lst_len == 2)
		sort_2(*stack_a);
	else if (lst_len == 3)
		sort_3(stack_a);
	else if (lst_len == 4)
		sort_4(stack_a, stack_b);
	else if (lst_len == 5)
		sort_5(stack_a, stack_b);
	else if (lst_len > 5)
		sort_more_than_5(stack_a, stack_b);
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
	sorter(&stack_a, &stack_b);
	free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	return (0);
}
