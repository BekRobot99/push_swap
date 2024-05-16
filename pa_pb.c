/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:29:07 by abekri            #+#    #+#             */
/*   Updated: 2024/05/14 19:03:57 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src) //
{
	t_stack_node *tmp;

	if (!dst || !src || !*src)
	{
		write(2, "Error: Null pointer received.\n", 29);
		return ;
	}
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (*dst)
		(*dst)->prev = tmp;
	tmp->next = *dst;
	tmp->prev = NULL;
	*dst = tmp;
}

void	pa(t_stack_node **a, t_stack_node **b, bool print) //
{
	if (!a || !b)
	{
		write(2, "Error: Null pointer received.\n", 29);
		return ;
	}
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool print) //
{
	if (!a || !b)
	{
		write(2, "Error: Null pointer received.\n", 29);
		return ;
	}
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
