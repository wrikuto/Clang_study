
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void changeHead(struct Node **head) {
    *head = NULL; // headの値を変更
}

int main() {
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 42;

    changeHead(&head);

    if (head == NULL) {
        printf("headはNULLです\n");
    } else {
        printf("headはNULLではありません\n");
    }
	// printf("%p\n", changeHead);
	free(head);
    return 0;
}