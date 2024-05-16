/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:29:30 by abekri            #+#    #+#             */
/*   Updated: 2024/05/16 16:38:17 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node)//	
{
	if (*b != cheapest_node->target_node && *a != cheapest_node)
	{
		rr(a, b, false);
		rotate_both(a, b, cheapest_node);
	}
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node) //
{
	int				num_rotations_a;
	t_stack_node	*current_a;
	int				num_rotations_b;
	t_stack_node	*current_b;

	num_rotations_a = 0;
	current_a = *a;
	while (current_a != cheapest_node)
	{
		current_a = current_a->next;
		num_rotations_a++;
	}
	num_rotations_b = 0;
	current_b = *b;
	while (current_b != cheapest_node->target_node)
	{
		current_b = current_b->next;
		num_rotations_b++;
	}
	if (num_rotations_a > num_rotations_b)
		rrr(a, b, num_rotations_b);
	else
		rrr(a, b, num_rotations_a);
	current_index(*a);
	current_index(*b);
}

static void	transfer_atob(t_stack_node **a, t_stack_node **b)
// Define a function that prepares the cheapest nodes on top of the stacks for pushing `a` nodes to stack `b`,
// until there are three nodes left in `a`
{
	t_stack_node *cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}

static void	transfer_btoa(t_stack_node **a, t_stack_node **b) //
{
	t_stack_node	*top_node;
	char			stack_name;

	top_node = (*b)->target_node;
	stack_name = 'a';
	while (*a != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(a, false);
			else
				rra(a, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(a, false);
			else
				rrb(a, false);
		}
	}
	pa(a, b, false);
}

static void	bring_min_to_top(t_stack_node **a) //
{
	t_stack_node *min_node;

	while (1)
	{
		min_node = get_min(*a);
		if ((*a)->nbr == min_node->nbr)
			break ;
		if (min_node->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b) //
{
	int size_a;

	size_a = stack_size(*a);
	if (size_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		prep_nodes_a(*a, *b);
		transfer_atob(a, b);
	}
	sort_three(a);
	while (*b)
	{
		prep_nodes_b(*a, *b);
		transfer_btoa(a, b);
	}
	current_index(*a);
	bring_min_to_top(a);
}
