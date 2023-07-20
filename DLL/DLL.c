#include"push_swap.h"

// DLL	*newstruct(int res_num)
// {
// 	DLL	*data;

// 	data = malloc(sizeof(DLL));
// 	if (data == NULL)
// 		return (NULL);
// 	data -> num = res_num;
// 	data -> next = NULL;
// 	data -> prev = NULL;
// 	return(data);
// }

// DLL	*createNode(DLL **head, int num)
// {
// 	DLL	*newNode;
// 	DLL	*current;

// 	newNode = newstruct(num);
// 	if (newNode == NULL)
// 		return (NULL);
// 	if (*head == NULL)
// 	{
// 		*head = newNode;
// 		(*head)->next = *head;
// 		(*head)->prev = *head;
// 	}
// 	else
// 	{
// 		current = *head;
// 		while (current->next != *head)
// 			current = current->next;

// 		current->next = newNode;
// 		newNode->next = *head;
// 		newNode->prev = current;
// 		(*head)->prev = newNode;
// 	}
// 	return (*head);
// }

// void printList(t_node *head)
// {
//     t_node *current = head;
//     if (head == NULL)
//     {
//         printf("List is empty.\n");
//         return;
//     }
//     do
//     {
//         printf("%d ", current->num);
//         current = current->next;
//     } while (current != head);

//     printf("\n");
// }

// void free_struct(t_node **head)
// {
// 	t_node	*current;
// 	t_node	*temp;

// 	if (*head == NULL)
// 		return ;
// 	current = *head;
// 	while (current->next != *head)
// 	{
// 		temp = current->next;
// 		free(current);
// 		current = temp;
// 	}
// 	free(current);
// 	*head = NULL;
// }



// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }