#include "push_swap.h"

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

int main(int argc, char **argv)
{
	t_node *head = NULL;
	int	i;

	i = 1;
	while (i <= (argc - 1))
	{
		if (is_contain_char(argv[i]))
		{
			printf("Invalid argument. try again.\n");
			return (0);
		}
		i++;
	}
	//リストを作成
	for (int i = 1; i < argc; i++)
	{
		int num = atoi(argv[i]);
		create_node(&head, num);
	}
	// リストの内容を表示
	printf("List: ");
	printList(head);

	char input[1000];
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
