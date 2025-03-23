/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:03:55 by vpogorel          #+#    #+#             */
/*   Updated: 2025/03/23 13:31:00 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	add(t_stack *stack, int number)
{
	t_node	*new_node;

	new_node = create_node(number);
	new_node->next = stack->head;
	stack->head = new_node;
}

void	rotate(t_stack *stack, t_node *currentNode, char s)
{
	t_node	*p;
	int		temp;

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

void	reverse_rotate(t_stack *stack, char s)
{
	t_node	*head;
	t_node	*current_node;
	int		temp;

	head = stack->head;
	current_node = head;
	current_node = current_node->next;
	while (current_node->next != NULL)
	{
		temp = head->number;
		head->number = current_node->number;
		current_node->number = temp;
		current_node = current_node->next;
	}
	temp = head->number;
	head->number = current_node->number;
	current_node->number = temp;
	if (s != 't')
		ft_printf("rr%c\n", s);
}

void	pop(t_stack *a)
{
	t_node	*temp;

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
	int	temp;

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
