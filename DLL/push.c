/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:39:05 by wrikuto           #+#    #+#             */
/*   Updated: 2023/07/20 22:43:08 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	src_join(t_node **src, t_node *second, t_node *last)
{
	if (second == last)
		*src = NULL;
	else
	{
		*src = second;
		second->prev = last;
		last->next = second;
	}
}

void	push(t_node **src, t_node **dest)
{
	t_node	*src_next;
	t_node	*src_last;
	t_node	*dest_next;
	t_node	*dest_last;

	if (*src == NULL)
		return ;
	src_next = (*src)->next;
	src_last = (*src)->prev;
	if (*dest == NULL)
	{
		*dest = *src;
		(*dest)->next = *dest;
		(*dest)->prev = *dest;
		src_join(src, src_next, src_last);
		return ;
	}
	dest_next = (*dest)->next;
	dest_last = (*dest)->prev;

	(*src)->next = dest_next;
	(*src)->prev = dest_last;
	dest_next->prev = *src;
	dest_last->next = *src;

	src_join(src, src_next, src_last);
}

// src == NULL
// dst == NULL
// src のヘッドが最後のノード