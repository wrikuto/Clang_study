#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include"SLL.h"

// typedef struct Node
// {
// 	int num;
// 	struct Node	*next;	
// } Node;

Node	*newstruct(int res_num)
{
	Node	*data;

	data = malloc(sizeof(Node));
	if (data == NULL)
		return (NULL);
	data -> num = res_num;
	data -> next = NULL;
	return(data);
}

Node	*createNode(Node **head, int num)
{
	Node	*newNode;
	Node	*current;

	newNode = newstruct(num);
	if (newNode == NULL)
		return (NULL);
	if (*head == NULL)
		*head = newNode;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = newNode;
	}
	return (*head);
}

void free_struct(Node **head)
{
	Node	*current;
	Node	*temp;

	current = *head;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*head = NULL;
}

void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->num);
        current = current->next;
    }
    printf("\n");
}

int is_contain_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (isalpha(str[i]))
		return (1);
		i++;
	}
	return (0);
}

int main(int argc, char* argv[])
{
    Node* head = NULL;
    if (argc == 2 && is_contain_char(argv[1]))
    {
        // コマンドライン引数に応じた操作を行う
        if (strcmp(argv[1], "list") == 0)
        {
            // リストの内容を表示
            printf("List: ");
            printList(head);
        }
        else if (strcmp(argv[1], "del") == 0)
        {
            // リストを削除
            free_struct(&head);
            printf("List deleted.\n");
        }
    }
    else
    {
        // コマンドライン引数が指定されていない場合はリストを作成
        for (int i = 1; i < argc; i++)
        {
            int num = atoi(argv[i]);
            createNode(&head, num);
        }

        // リストの内容を表示
        printf("List: ");
        printList(head);
    }

    char input[100];
    while (1)
    {
        printf("Enter 'list', 'del', 'exit' ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // 改行文字を削除
		if (strcmp(input, "list") == 0)
			printList(head);
        if (strcmp(input, "exit") == 0)
            break;
		if (strcmp(input, "del") == 0)
		{
			 free_struct(&head);
			 printf("deleted\n");
		}
    }
            free_struct(&head);
            printf("Program finish and List deleted.\n");
    return 0;
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}