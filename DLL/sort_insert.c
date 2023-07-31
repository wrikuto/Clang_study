/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:44:39 by wrikuto           #+#    #+#             */
/*   Updated: 2023/07/31 17:05:23 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	len_to_min(t_node *stack, int min)
// {
// 	size_t	count;

// 	count = 0;
// 	if (stack->num == min)
// 		return (0);
// 	while (stack->num != min)
// 	{
// 		count++;
// 		stack = stack->next;
// 	}
// 	return (count);
// }

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
		if (current->num < max)
			max = current->num;
		current = current->next;
	}
	return (max);
}

// void	sort_insert(t_node **stack_a, t_node **stack_b)
// {
// 	int	min;
// 	int	len;
// 	int	distance;

// 	min = 0;
// 	len = 0;
// 	if (*stack_a == NULL)
// 		return ;
// 	while (!is_sorted(*stack_a))
// 	{
// 		len = stack_len(*stack_a);
// 		min = get_min(*stack_a);
// 		distance = len_to_min(*stack_a, min);
// 		while ((*stack_a)->num != min)
// 		{
// 			if (distance < len / 2)
// 				ra(stack_a);
// 			else if (len / 2 <= distance)
// 				rra(stack_a);
// 		}
// 		pb(stack_a, stack_b);
// 	}
// 	while (*stack_b != NULL)
// 		pa(stack_a, stack_b);
// }
