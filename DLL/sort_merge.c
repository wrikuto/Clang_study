/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:00:53 by wrikuto           #+#    #+#             */
/*   Updated: 2023/07/26 22:41:12 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_to_before_harf(t_node *stack, t_node *before_harf)
{
	size_t	len;
	t_node	*current;

	len = 0;
	current = stack;
	while (current != NULL && current != before_harf)
	{
		len++;
		current = current->next;
	}
	return (len);
}

// 右半分をマージする。
void	insert_merge(t_node **stack_a, t_node **stack_b, t_node *before_harf)
{
	t_node	*head;

	head = *stack_b;
	while ((*stack_a) != before_harf)
	{
		if ((*stack_b)->num > (*stack_a)->num || (*stack_b)->next == head)
			pb(stack_a, stack_b);
		else
		{
			while (((*stack_b)->num) < (*stack_a)->num)
				rb(stack_b);
			pb(stack_a, stack_b);
		}
		while (*stack_b != head || \
		(stack_len(*stack_b) == 2 && ((*stack_b)->num > (*stack_b)->next->num)))
			rb(stack_b);
	}
	if (is_sorted(*stack_b))
	{
		while (stack_b != NULL)
			push_all_a(stack_a, stack_b);
	}
	while (stack_b != NULL)
		rrb_pa_ra(stack_a, stack_b);
}

void	recursive(t_node **stack_a, t_node **stack_b, t_node *before_harf)
{
	size_t	i;
	size_t	len;
	t_node	*harf;
	t_node	*head;

	i = 0;
	harf = *stack_a;
	head = *stack_a;
	len = len_to_before_harf(*stack_a, before_harf);
	while (i++ <= len)
		harf = harf->next;
	if ((*stack_a) != harf)
		recursive(stack_a, stack_b, harf);
	if (harf != before_harf)
	{
		while (*stack_a != harf)
			ra(stack_a);
		recursive(stack_a, stack_b, before_harf);
	}
	if (is_sorted(*stack_a))
		return ;
	while (*stack_a != head)
		rra_pb(stack_a, stack_b);
	insert_merge(stack_a, stack_b, before_harf);
}

void	sort_merge(t_node **stack_a, t_node **stack_b)
{
	recursive(stack_a, stack_b, *stack_a);
}
