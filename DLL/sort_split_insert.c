/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_split_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:46:29 by wrikuto           #+#    #+#             */
/*   Updated: 2023/07/31 17:03:03 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	get_center(t_node *stack, int mid)
{
	size_t	i;
	size_t	len;
	int		center_num;
	int		dif;

	i = 0;
	len = stack_len(stack);
	center_num = stack->num;
	while (i < len)
	{
		dif = ft_abs(mid - center_num);
		if (dif > ft_abs(mid - stack->num))
			center_num = stack->num;
		i++;
	}
	return (center_num);
}

int	grouping(t_node **stack_a, t_node **stack_b)
{
	int		min_count;
	int		max;
	int		mid;
	size_t	len;

	min_count = get_min(*stack_a);
	max = get_max(*stack_a);
	mid = get_center(*stack_a, (min_count + ((max - min_count) / 2)));
	len = stack_len(*stack_a);
	min_count = 0;
	while ((size_t)min_count < len)
	{
		if ((*stack_a)->num <= mid)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		min_count++;
	}
	while (*stack_a != NULL)
		pb(stack_a, stack_b);
	return (mid);
}

static int	len_to_max(t_node *stack, int max)
{
	size_t	count;

	count = 0;
	if (stack->num == max)
		return (0);
	while (stack->num != max)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}


void	sort_split_insert(t_node **stack_a, t_node **stack_b)
{
	int	max;
	int	len;
	int	distance;

	max = 0;
	len = 0;
	if (*stack_a == NULL)
		return ;
	while (!is_sorted(*stack_a))
	{
		len = stack_len(*stack_a);
		max = get_max(*stack_a);
		distance = len_to_max(*stack_a, max);
		while ((*stack_a)->num != max)
		{
			if (distance < len / 2)
				ra(stack_a);
			else if (len / 2 <= distance)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	while (*stack_b != NULL)
		pa(stack_a, stack_b);
}
