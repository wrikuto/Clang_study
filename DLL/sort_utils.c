/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:07:04 by wrikuto           #+#    #+#             */
/*   Updated: 2023/07/24 23:07:15 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_list(t_node **stack_a)
{
	int		i;
	t_node	*current;

	if (*stack_a == NULL)
		return (0);
	i = 1;
	current = (*stack_a)->next;
	while (current != *stack_a)
	{
		current = current->next;
		i++;
	}
	return (i);
}