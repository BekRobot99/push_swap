/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:32:26 by abekri            #+#    #+#             */
/*   Updated: 2024/05/16 17:45:04 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rra(t_stack_node **a, bool print)
{
	t_stack_node	*last;

	if (!*a || !(*a)->next)
		return ;
	last = get_last(*a);
	last->prev->next = NULL;
	last->next = *a;
	last->prev = NULL;
	*a = last;
	last->next->prev = last;
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool print)
{
	t_stack_node	*last;

	if (!*b || !(*b)->next)
		return ;
	last = get_last(*b);
	last->prev->next = NULL;
	last->next = *b;
	last->prev = NULL;
	*b = last;
	last->next->prev = last;
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	rra(a, print);
	rrb(b, print);
	if (!print)
		ft_printf("rrr\n");
}
