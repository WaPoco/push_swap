#include "push_swap.h"

Node	*createNode(int number)
{
	Node *new_node = (Node*)malloc(sizeof(Node));
	if (!new_node)
	{
		printf("Error allocating memory!");
		exit(1);
	}
	new_node->number = number;
	new_node->next = NULL;
	return (new_node);
}

void	initializeStack(Stack *stack)
{
    stack->head = NULL;
}

void	add(Stack *stack, int number)
{
	Node *new_node = createNode(number);
	new_node->next = stack->head;
	stack->head = new_node;
}

void	printStack(Node *currentNode)
{
	Node *p;

	p = currentNode;
	if (p->next == NULL)
	{
		printf("%d ", p->number);
		return ;
	}
	else
		printStack(p->next);
	printf(" %d ", p->number);
}

void	rotateStack(Stack *stack, Node *currentNode)
{
	Node *p;
	int	temp;

	p = currentNode;
	if (p->next == NULL)
	{
		temp = stack->head->number;
		stack->head->number = currentNode->number;
		currentNode->number = temp;
		currentNode = currentNode->next;
		return ;
	}
	else
		rotateStack(stack, p->next);
	temp = stack->head->number;
	stack->head->number = currentNode->number;
	currentNode->number = temp;
	currentNode = currentNode->next;
}

void	reverseRotateStack(Stack *stack)
{
	Node	*head;
	Node	*currentNode;
	int	temp;

	head = stack->head;
	currentNode = head;
	currentNode = currentNode->next;
	while (currentNode->next != NULL)
	{
		temp = head->number;
		head->number = currentNode->number;
		currentNode->number = temp;
		currentNode = currentNode->next;
	}
	temp = head->number;
	head->number = currentNode->number;
	currentNode->number = temp;
}

void	swap(Stack *stack)
{
	int	temp;
	Node	*next;

	next = stack->head->next;
	if(stack->head == NULL || next == NULL)
		return ;
	temp = stack->head->number;
	stack->head->number = next->number;
	next->number = temp;
}

void	push(Stack *a, Stack *b)
{
	//...
}