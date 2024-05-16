/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:28:10 by abekri            #+#    #+#             */
/*   Updated: 2024/05/14 16:16:51 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*third;

	first = *a;
	second = (*a)->next;
	third = (*a)->next->next;
	if ((first->data > second->data) && (first->data > third->data))
	{
		ra(a, false);
		return ;
	}
	if ((second->data > first->data) && (second->data > third->data))
	{
		rra(a, false);
		return ;
	}
	if ((third->data > first->data) && (third->data > second->data)
		&& (second->data > first->data))
	{
		sa(a, false);
		return ;
	}
}
