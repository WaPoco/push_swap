/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:31:37 by vpogorel          #+#    #+#             */
/*   Updated: 2025/03/21 17:33:17 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	add(t_stack *stack, int number)
{
	t_node *new_node = createNode(number);
	new_node->next = stack->head;
	stack->head = new_node;
}

void	rotate(t_stack *stack, t_node *currentNode, char s)
{
	t_node *p;
	int	temp;

	p = currentNode;
	if (p->next == NULL)
	{
		temp = stack->head->number;
		stack->head->number = currentNode->number;
		currentNode->number = temp;
		currentNode = currentNode->next;
		if (s != 't')
			ft_printf("r%c\n", s);
		return ;
	}
	else
		rotate(stack, p->next, s);
	temp = stack->head->number;
	stack->head->number = currentNode->number;
	currentNode->number = temp;
	currentNode = currentNode->next;
}

void	reverseRotate(t_stack *stack, char s)
{
	t_node	*head;
	t_node	*currentNode;
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
	if (s != 't')
		ft_printf("rr%c\n", s);
}

void	swap(t_stack *stack, char s)
{
	int	temp;
	t_node	*next;

	next = stack->head->next;
	if(stack->head == NULL || next == NULL)
		return ;
	temp = stack->head->number;
	stack->head->number = next->number;
	next->number = temp;
	ft_printf("s%c\n", s);
}

void	pop(t_stack *a)
{
	t_node *temp;

	if (a->head == NULL)
	{
		printf("Stack is empty\n");
		return ;
	}
	temp = a->head;
	a->head = a->head->next;
	free(temp);
}

void	push(t_stacks *stacks, char dstack)
{
	int temp;

	if (dstack == 'a')
	{
		temp = stacks->stack_b->head->number;
		pop(stacks->stack_b);
		add(stacks->stack_a, temp);
		ft_printf("pa\n");
	}
	else
	{
		temp = stacks->stack_a->head->number;
		pop(stacks->stack_a);
		add(stacks->stack_b, temp);
		ft_printf("pb\n");
	}
}
