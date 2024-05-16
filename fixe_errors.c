/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixe_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 05:01:35 by abekri            #+#    #+#             */
/*   Updated: 2024/05/13 01:13:51 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	structure_error(char *str_n)
{
	if (!(str_n[0] == '-' || str_n[0] == '+' || ('0' <= str_n[0]
				&& str_n[0] <= '9')))
		return (1);
	if ((str_n[0] == '-' || str_n[0] == '+') && !(('0' <= str_n[1]
				&& str_n[1] <= '9')))
		return (1);
	if (str_n[0] == '-' || str_n[0] == '+')
		str_n++;
	while (*str_n != '\0')
	{
		if (!('0' <= *str_n && *str_n <= '9'))
			return (1);
		str_n++;
	}
	return (0);
}

int	num_repeated(t_stack_node *a, int n)
{
	if (a == NULL)
		return (0);
	while (a != NULL)
	{
		if (a->data == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	empty_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*tmp;

	current = *stack;
	if (current == NULL)
		return ;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = NULL;
		current = tmp;
	}
	*stack = NULL;
}

void	eleminate_errors(t_stack_node **a)
{
	if (*a == NULL)
	{
		ft_printf("Error: Stack is empty\n");
		return ;
	}
	empty_stack(a);
	ft_printf("Error\n");
	exit(1);
}
