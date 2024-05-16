/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:27:17 by abekri            #+#    #+#             */
/*   Updated: 2024/05/16 16:33:15 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;
	int	len;

	len = stack_size(stack);
	i = 0;
	if (stack == NULL)
	{
		ft_printf("Error: Empty stack received.\n");
		return ;
	}
	median = len / 2;
	while (stack != NULL)
	{
		stack->index = i;
		if (i >= median)
			stack->above_median = false;
		else
			stack->above_median = true;
		stack = stack->next;
		++i;
	}
}

static long	find_best_match_index(t_stack_node *a, t_stack_node *b)//3
{
	t_stack_node	*current_b;
	long			best_match_index;

	best_match_index = LONG_MIN;
	current_b = b;
	while (current_b)
	{
		if (current_b->nbr < a->nbr && current_b->nbr > best_match_index)
		{
			best_match_index = current_b->nbr;
		}
		current_b = current_b->next;
	}
	return (best_match_index);
}

static void	set_target_node(t_stack_node *a, t_stack_node *b,
		long best_match_index)//3
{
	t_stack_node	*target_node;
	t_stack_node	*current_b;

	target_node = NULL;
	current_b = b;
	while (current_b)
	{
		if (current_b->nbr == best_match_index)
		{
			target_node = current_b;
			break ;
		}
		current_b = current_b->next;
	}
	if (!target_node)
	{
		target_node = get_max(b);
	}
	a->target_node = target_node;
}

static void	set_target_a(t_stack_node *a, t_stack_node *b) //3
{
	long	best_match_index;

	while (a)
	{
		best_match_index = find_best_match_index(a, b);
		set_target_node(a, b, best_match_index);
		a = a->next;
	}
}

static void	calculate_push_cost(t_stack_node *node, int len_a, int len_b)//2
{
	if (node->above_median)
		node->push_cost = node->index;
	else
		node->push_cost = len_a - node->index;
	if (node->target_node)
	{
		if (node->target_node->above_median)
		{
			node->push_cost += node->target_node->index;
		}
		else
		{
			node->push_cost += len_b - node->target_node->index;
		}
	}
}

static void	cost_analysis_a(t_stack_node *a, t_stack_node *b)//2
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		calculate_push_cost(a, len_a, len_b);
		a = a->next;
	}
}

t_stack_node	*find_cheapest_recursively(t_stack_node *stack,//1
		t_stack_node *cheapest_node, long cheapest_value)
{
	if (!stack)
	{
		return (cheapest_node);
	}
	if (stack->push_cost < cheapest_value)
	{
		cheapest_value = stack->push_cost;
		cheapest_node = stack;
	}
	return (find_cheapest_recursively(stack->next, cheapest_node,
			cheapest_value));
}

void	set_cheapest(t_stack_node *stack)//1
{
	t_stack_node	*cheapest_node;

	if (!stack)
	{
		return ;
	}
	cheapest_node = find_cheapest_recursively(stack, NULL, LONG_MAX);
	if (cheapest_node)
	{
		cheapest_node->cheapest = true;
	}
}

void	prep_nodes_a(t_stack_node *a, t_stack_node *b)//
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
