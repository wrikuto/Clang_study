#include "push_swap.h"

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
	for (int i = 1; i < argc; i++)
	{
		int num = atoi(argv[i]);
		create_node(&head, num);
	}
	printf("List: ");
	printList(head);

	free_struct(&head);
	printf("Program finish and List deleted.\n");
	return 0;
}
