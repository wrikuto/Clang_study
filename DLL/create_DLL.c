#include "push_swap.h"

t_node	*newstruct(int res_num)
{
	t_node	*data;

	data = malloc(sizeof(t_node));
	if (data == NULL)
		return (NULL);
	data -> num = res_num;
	data -> next = NULL;
	data -> prev = NULL;
	return(data);
}

t_node	*create_node(t_node **head, int num)
{
	t_node	*newNode;
	t_node	*current;

	newNode = newstruct(num);
	if (newNode == NULL)
		return (NULL);
	if (*head == NULL)
	{
		*head = newNode;
		(*head)->next = *head;
		(*head)->prev = *head;
	}
	else
	{
		current = *head;
		while (current->next != *head)
			current = current->next;

		current->next = newNode;
		newNode->next = *head;
		newNode->prev = current;
		(*head)->prev = newNode;
	}
	return (*head);
}