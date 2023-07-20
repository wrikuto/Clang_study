/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:46:37 by wrikuto           #+#    #+#             */
/*   Updated: 2023/07/20 16:50:55 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void printList(t_node *head)
// {
//     t_node *current = head;
//     if (head == NULL)
//     {
//         printf("List is empty.\n");
//         return;
//     }
// // hode
//     do
//     {
//         printf("%d ", current->num);
//         current = current->next;
//     } while (current != head);

//     printf("\n");
// }

void	free_struct(t_node **head)
{
	t_node	*current;
	t_node	*temp;

	if (*head == NULL)
		return ;
	current = *head;
	while (current->next != *head)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	free(current);
	*head = NULL;
}


