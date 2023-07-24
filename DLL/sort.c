/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:44:39 by wrikuto           #+#    #+#             */
/*   Updated: 2023/07/24 15:21:21 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

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

int	stack_len(t_node *stack)
{
	int		len;
	t_node	*current;

	len = 0;
	current = stack;
	while (current != NULL && current->next != stack)
	{
		len++;
		current = current->next;
	}
	return (len);
}


int	get_min(t_node *stack)
{
	int		min;
	t_node	*current;

	min = INT_MAX;
	if (stack->num < min)
		min = stack->num;
	current = stack->next;
	while (current != NULL && current != stack)
	{
		if (current->num < min)
			min = current->num;
		current = current->next;
	}
	printf("min: %d\n", min);
	return (min);
}

void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	int	min;

	if (*stack_a == NULL)
		return ;
	while (!is_sorted(*stack_a))
	{
		min = get_min(*stack_a);
		while ((*stack_a)->num != min)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	while (*stack_b != NULL)
		pa(stack_a, stack_b);
}
