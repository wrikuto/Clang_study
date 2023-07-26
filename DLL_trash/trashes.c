
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


void	push(t_node **src, t_node **dest)
{
	t_node	*src_next;
	t_node	*src_last;
	// t_node	*dest_next;
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
	// dest_next = (*dest)->next;
	dest_last = (*dest)->prev;

	(*src)->next = *dest;
	(*src)->prev = dest_last;
	(*dest)->prev = *src;
	dest_last->next = *src;

	*dest = *src;
	src_join(src, src_next, src_last);
}

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
	// printList(stack_a);
	// printList(stack_b);
	// printf("\n");

	if (argc == 3)
		ra(&stack_a);
	else if (argc == 4)
		sort_three_elements(&stack_a);
	else if (argc == 5 || argc == 6)
		sort_five_elements(&stack_a, &stack_b, argc - 1);
	else
		sort_insert(&stack_a, &stack_b);

	// printList(stack_a);

	free_list(&stack_a);
	free_list(&stack_b);

	return (0);
}




__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}