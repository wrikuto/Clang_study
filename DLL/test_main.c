/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 22:37:15 by wrikuto           #+#    #+#             */
/*   Updated: 2023/07/26 22:42:54 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

#include "push_swap.h"

void printList(t_node *head)
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

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (chk_num_string(argv[1]) == 0 && argv[2] == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (chk_args(&argv[1]) == 0 && argv[2] != NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	create_list(&argv[1], &stack_a);
	
	printList(*stack_a);

	sort_merge(&stack_a, &stack_b);

	printList(*stack_a)

	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}