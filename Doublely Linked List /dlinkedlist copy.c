#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
	struct node* prev;
};

struct node* addNewNode(int val, struct node* previous)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = previous;
    return newNode;
}
void printForward(struct node* topNode)
{
    for(struct node* i = topNode; i != NULL; i = i->next)
    {
        printf("%d ", i->data);
    }
    printf("\n");
}
void printReverse(struct node* bottomNode)
{
    struct node* i = bottomNode;
    while(i != NULL)
    {
        printf("%d ", i->data);
        i = i->prev;
    }
    printf("\n");
}
void dealloc(struct node* topNode)
{
    if(topNode->next != NULL)
    {
        dealloc(topNode->next);
    }
    topNode->next = NULL;
    topNode->prev = NULL;
    free(topNode);

}
int main()
{
	struct node* head;
	int input;
	printf("Enter the number you want to insert: ");
	scanf("%d", &input);
	head = addNewNode(input, NULL);
	struct node* tail = head;
	for(int i = 1; i < 10; i++)
	{
		printf("Enter the number you want to insert: ");
		scanf("%d", &input);
		tail->next = addNewNode(input, tail);
		tail = tail->next;
	}	
	printf("Printing forward: ");
	printForward(head);
	printf("\nPrinting reverse: ");
	printReverse(tail);
	dealloc(head);
	tail = NULL;
	head = NULL;
	return 0;
}

