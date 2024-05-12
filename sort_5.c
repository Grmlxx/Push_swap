/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:23:42 by alamaoui          #+#    #+#             */
/*   Updated: 2024/05/10 17:29:17 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_5(t_node **stack_a, t_node **stack_b)
{
	int	small;
	int	small_index;

	small = smallest(*stack_a);
	small_index = smallest_index(*stack_a, small);
	while ((*stack_a)->value != small)
	{
		if (small_index > ft_lstsize(*stack_a) / 2)
			rra(stack_a, 1);
		else
			ra(stack_a, 1);
	}
	if (is_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b, 1);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b, 1);
}
