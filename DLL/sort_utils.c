/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:07:04 by wrikuto           #+#    #+#             */
/*   Updated: 2023/07/25 15:19:22 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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