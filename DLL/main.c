/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:34:00 by wrikuto           #+#    #+#             */
/*   Updated: 2023/07/20 23:16:45 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (chk_args(&argv[1]) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	create_list(&argv[1], &stack_a);
	if (stack_a == NULL)
		return (0);
	
	printList(stack_a);
	printList(stack_b);
	printf("\n");
	

	push(&stack_a, &stack_b);


	printList(stack_a);
	printList(stack_b);
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}