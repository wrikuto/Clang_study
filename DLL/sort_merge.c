/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:00:53 by wrikuto           #+#    #+#             */
/*   Updated: 2023/07/27 18:12:01 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include<stdio.h>

static void printList(t_node *head)
{
    t_node *current = head;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
// hode
    do
    {
        printf("%d ", current->num);
        current = current->next;
    } while (current != head);

    printf("\n");
}


int	len_to_before_harf(t_node *stack, t_node *before_harf)
{
	size_t	len;
	t_node	*current;

	len = 1;
	current = stack->next;
	while (current != NULL && current != before_harf)
	{
		len++;
		current = current->next;
	}
	if (stack == before_harf)
		len--;
	return (len);
}

// 右半分をマージする。
void	insert_merge(t_node **stack_a, t_node **stack_b, t_node *before_harf)
{
	t_node	*head;

							printf("insert_harf:	%d\n\n", (before_harf)->num);
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

	i = 1;
	harf = (*stack_a);
	head = *stack_a;
	len = len_to_before_harf(*stack_a, before_harf);
	// return ;
	while (i++ <= len / 2)
	{
		harf = harf->next;
	}
	// return ;
	if ((*stack_a) != harf)
	{

		recursive(stack_a, stack_b, harf);
	}
	if ((*stack_a) != harf && harf != before_harf)
	{
		while (*stack_a != harf)
			ra(stack_a);
		recursive(stack_a, stack_b, before_harf);
	}
	if (is_sorted(*stack_a))
		return ;
	while (*stack_a != head)
		rra_pb(stack_a, stack_b);
											printf("before_harf: %d\n", (before_harf)->num);
											printf("harf:	%d\n\n", (harf)->num);
	insert_merge(stack_a, stack_b, before_harf);
}

void	sort_merge(t_node **stack_a, t_node **stack_b)
{
	recursive(stack_a, stack_b, (*stack_a));
	printList(*stack_b);
}
