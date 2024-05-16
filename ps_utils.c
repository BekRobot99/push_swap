/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:29:01 by abekri            #+#    #+#             */
/*   Updated: 2024/05/16 16:34:12 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack_node *stack)
{
	int	length;

	length = 0;
	while (stack != NULL)
	{
		length++;
		stack = stack->next;
	}
	return (length);
}

bool	stack_sorted(t_stack_node *stack)
{
	if (stack == NULL || stack->next == NULL)
	{
		return (true);
	}
	while (stack->next != NULL)
	{
		if (stack->data > stack->next->data)
		{
			return (false);
		}
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*get_last(t_stack_node *stack)
{
	if (stack == NULL)
	{
		return (NULL);
	}
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}

t_stack_node	*get_min(t_stack_node *stack)
{
	long			min_value;
	t_stack_node	*min_node;

	if (stack == NULL)
	{
		return (NULL);
	}
	min_node = stack;
	min_value = LONG_MAX;
	while (stack != NULL)
	{
		if (stack->nbr < min_value)
		{
			min_value = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack_node	*get_max(t_stack_node *stack)
{
	long			max_value;
	t_stack_node	*max_node;

	if (stack == NULL)
	{
		return (NULL);
	}
	max_node = stack;
	max_value = LONG_MIN;
	while (stack != NULL)
	{
		if (stack->nbr > max_value)
		{
			max_value = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
