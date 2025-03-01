#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

typedef struct Node
{
	int number;
	struct Node	*next;
} Node;

typedef struct Stack
{
	Node *head;
} Stack;

void	add(Stack *stack, int number);
void	initializeStack(Stack *stack);
Node	*createNode(int number);
void	printStack(Node *currentNode);
void	rotateStack(Stack *stack, Node *currentNode);
void	reverseRotateStack(Stack *stack);
void	swap(Stack *stack);
