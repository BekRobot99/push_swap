/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:29:16 by abekri            #+#    #+#             */
/*   Updated: 2024/05/16 16:34:12 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	change_a_to_l(const char *s)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	result *= sign;
	return (result);
}

static void	add_node(t_stack_node **stack, int n)
{
	t_stack_node	*last_node;
	t_stack_node	*node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (*stack)
	{
		last_node = get_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
	else
	{
		*stack = node;
		node->prev = NULL;
	}
}

void	start_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (structure_error(argv[i]))
			eleminate_errors(a);
		n = change_a_to_l(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			eleminate_errors(a);
		if (num_repeated(*a, (int)n))
			eleminate_errors(a);
		add_node(a, (int)n);
		i++;
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	if (stack->cheapest)
		return (stack);
	return (get_cheapest(stack->next));
}

void	prep_for_push(t_stack_node **stack, t_stack_node *top_node,
		char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
