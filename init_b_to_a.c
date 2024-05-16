/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:50:08 by abekri            #+#    #+#             */
/*   Updated: 2024/05/16 16:33:43 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_node	*find_closest_bigger(t_stack_node *a, int nbr)
{
	long			closest_bigger;
	t_stack_node	*target_node;

	closest_bigger = LONG_MAX;
	target_node = NULL;
	while (a)
	{
		if (a->nbr > nbr && a->nbr < closest_bigger)
		{
			closest_bigger = a->nbr;
			target_node = a;
		}
		a = a->next;
	}
	return (target_node);
}

static t_stack_node	*find_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*target_node;

	target_node = find_closest_bigger(a, b->nbr);
	if (target_node == NULL)
		return (get_min(a));
	else
		return (target_node);
}

static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	while (b)
	{
		b->target_node = find_target_node(a, b);
		b = b->next;
	}
}

void	prep_nodes_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
