/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:07:04 by wrikuto           #+#    #+#             */
/*   Updated: 2023/07/31 23:03:57 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stack_len(t_node *stack)
{
	size_t	len;
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

int	get_min(t_node *stack)
{
	int		min;
	t_node	*current;

	min = INT_MAX;
	if (stack->num <= min)
		min = stack->num;
	current = stack->next;
	while (current != NULL && current != stack)
	{
		if (current->num < min)
			min = current->num;
		current = current->next;
	}
	return (min);
}

int	get_max(t_node *stack)
{
	int		max;
	t_node	*current;

	max = INT_MIN;
	if (stack->num >= max)
		max = stack->num;
	current = stack->next;
	while (current != NULL && current != stack)
	{
		if (current->num > max)
			max = current->num;
		current = current->next;
	}
	return (max);
}

void	select_sort(t_node **stack_a, t_node **stack_b)
{
	int	len;

	len = stack_len(*stack_a);
	if (*stack_a == NULL || is_sorted(*stack_a))
		return ;
	if (len == 2 && ((*stack_a)->num) > ((*stack_a)->next->num))
		ra(stack_a);
	else if (len == 3)
		sort_three_elements(stack_a);
	else if (len == 4 || len == 5)
		sort_five_or_four(stack_a, stack_b, len);
	else
		sort_split_insert(stack_a, stack_b);
	// test!!!!!!!!
}
