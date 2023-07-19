#include<stdio.h>
#include<stdlib.h>

typedef struct 	s_node
{
	int				n;
	struct	s_node	*next;
}				t_node;

t_node	*create_node(int data)
{
	t_node *newNode;
	
	newNode = malloc(sizeof(t_node));
	if (newNode == NULL)
		return (0);
	newNode -> n = data;
	newNode -> next = NULL;
	return (newNode);
}

void	insert_node()

int main()
{
	int		i;
	int arr[] = {1, 2, 3, 4, 5};
	t_node	*head;

	i = 0;
	head = NULL;
	while (arr[i] != NULL)
	{
		t_node	*newNode;
		newNode = malloc(sizeof(t_node));
		newNode -> n = arr[i];
		newNode -> next = NULL;
	}


	return (0);
}