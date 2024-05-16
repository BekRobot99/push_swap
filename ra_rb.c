/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:06:15 by abekri            #+#    #+#             */
/*   Updated: 2024/05/14 18:34:59 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ra(t_stack_node **a, bool print)
{
	t_stack_node	*last_node;

	if (!*a || !(*a)->next)
		return ;
	last_node = *a;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = *a;
	*a = (*a)->next;
	(*a)->previous = NULL;
	last_node->next->previous = last_node;
	last_node->next->next = NULL;
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, bool print)
{
	t_stack_node	*last_node;

	if (!*b || !(*b)->next)
		return ;
	last_node = *b;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = *b;
	*b = (*b)->next;
	(*b)->previous = NULL;
	last_node->next->previous = last_node;
	last_node->next->next = NULL;
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	ra(a, print);
	rb(b, print);
	if (!print)
		ft_ft_printf("rr\n");
}
