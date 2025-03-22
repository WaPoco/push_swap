/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:26:06 by vpogorel          #+#    #+#             */
/*   Updated: 2025/03/21 17:32:11 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

t_node	*createNode(int number)
{
	t_node *new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		printf("Error allocating memory!");
		exit(1);
	}
	new_node->number = number;
	new_node->next = NULL;
	return (new_node);
}

void	initializeStack(t_stack *stack)
{
    stack->head = NULL;
}

t_stack	*createStack(int arg0, char **args)
{
	int			i;
	t_stack		*stack;
	t_node		*tmp;

	i = 1;
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		printf("Error allocating memory!");
		exit(1);
	}
	if (arg0 == 1)
	{
		initializeStack(stack);
		return (stack);
	}
	stack->head = createNode(ft_atoi(args[i]));
	tmp = stack->head;
	while (++i < arg0)
	{
		tmp->next = createNode(ft_atoi(args[i]));
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (stack);
}

int	stack_len(t_stack *stack)
{
	t_node	*temp;
	int	i;

	i = 0;
	temp = stack->head;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	printStack(t_node *currentNode)
{
	t_node *p;

	p = currentNode;
	while (p != NULL)
	{
		printf("%d \n", p->number);
		p = p->next;
	}
}
