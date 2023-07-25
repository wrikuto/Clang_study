/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:07:04 by wrikuto           #+#    #+#             */
/*   Updated: 2023/07/25 21:57:04 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_len(t_node *stack)
{
	int		len;
	t_node	*current;

	len = 1;
	current = stack->next;
	while (current != NULL && current != stack)
	{
		len++;
		current = current->next;
	}
	return (len);
}

int	wrong_arg(int argc)
{
	if (argc)
		argc += 0;
	write(2, "Error\n", 6);
	return (0);
}

int	is_sorted(t_node *stack)
{
	t_node	*current;

	current = stack;
	while (current != NULL && current->next != stack)
	{
		if ((current->num) > (current->next->num))
			return (0);
		current = current->next;
	}
	return (1);
}

void	select_sort(t_node **stack_a, t_node **stack_b)
{
	int	len;

	len = stack_len(*stack_a);
	if (*stack_a == NULL)
		return ;
	if (is_sorted(*stack_a))
		return ;
	if (len == 2 && ((*stack_a)->num) > ((*stack_a)->next->num))
		ra(stack_a);
	else if (len == 3)
		sort_three_elements(stack_a);
	else if (len == 4 || len == 5)
		sort_five_or_four(stack_a, stack_b, len);
	else
		sort_insert(stack_a, stack_b);
}