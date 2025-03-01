#include "push_swap.h"

int	main(int arg0, char **args)
{
	int i = 1;
	Stack *a;

	initializeStack(a);
	while (i < arg0)
		add(a, atoi(args[i++]));
	printStack(a->head);
	printf("\n");
	reverseRotateStack(a);
	printStack(a->head);
	rotateStack(a, a->head);
	printf("\n");
	printStack(a->head);
	rotateStack(a, a->head);
	printf("\n");
	printStack(a->head);
	swap(a);
	printf("\n");
	printStack(a->head);
	return (1);
}
