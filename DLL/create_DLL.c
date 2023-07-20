/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_DLL.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:42:44 by wrikuto           #+#    #+#             */
/*   Updated: 2023/07/20 16:45:48 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int res_num)
{
	t_node	*data;

	data = malloc(sizeof(t_node));
	if (data == NULL)
		return (NULL);
	data -> num = res_num;
	data -> next = NULL;
	data -> prev = NULL;
	return (data);
}

t_node	*add_node(t_node **head, int num)
{
	t_node	*new;
	t_node	*current;

	new = newstruct(num);
	if (new == NULL)
		return (NULL);
	if (*head == NULL)
	{
		*head = new;
		(*head)->next = *head;
		(*head)->prev = *head;
	}
	else
	{
		current = *head;
		while (current->next != *head)
			current = current->next;
		current->next = new;
		new->next = *head;
		new->prev = current;
		(*head)->prev = new;
	}
	return (*head);
}
