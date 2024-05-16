/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:29:37 by abekri            #+#    #+#             */
/*   Updated: 2024/05/12 23:41:53 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **a, bool print)
{
	if (!*a || !(*a)->next)
		return ;
	*a = (*a)->next;
	(*a)->prev->prev = *a;
	(*a)->prev->next = (*a)->next;
	if ((*a)->next)
		(*a)->next->prev = (*a)->prev;
	(*a)->next = (*a)->prev;
	(*a)->prev = NULL;
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print)
{
	if (!*b || !(*b)->next)
		return ;
	*b = (*b)->next;
	(*b)->prev->prev = *b;
	(*b)->prev->next = (*b)->next;
	if ((*b)->next)
		(*b)->next->prev = (*b)->prev;
	(*b)->next = (*b)->prev;
	(*b)->prev = NULL;
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	sa(a, print);
	sb(b, print);
	if (!print)
		ft_printf("ss\n");
}
