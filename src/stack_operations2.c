/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:41:20 by vpogorel          #+#    #+#             */
/*   Updated: 2025/03/23 13:23:46 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	find_stack_min_max(t_stack *stack)
{
	t_node	*temp;
	int		index;

	if (stack->head == NULL)
		return ;
	index = 0;
	temp = stack->head;
	stack->min = temp->number;
	stack->max = temp->number;
	while (temp != NULL)
	{
		if (temp->number <= stack->min)
		{
			stack->min = temp->number;
			stack->index_min = index;
		}
		if (temp->number >= stack->max)
		{
			stack->max = temp->number;
			stack->index_max = index;
		}
		temp = temp->next;
		index++;
	}
}

t_node	*create_node(int number)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		printf("Error allocating memory!");
		exit(1);
	}
	new_node->number = number;
	new_node->next = NULL;
	return (new_node);
}

void	initialize_stack(t_stack *stack)
{
	stack->head = NULL;
}

t_stack	*create_stack(int arg0, char **args)
{
	int			i;
	t_stack		*stack;
	t_node		*tmp;

	i = 1;
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		ft_printf("Error allocating memory!");
		exit(1);
	}
	if (arg0 == 1)
	{
		initialize_stack(stack);
		return (stack);
	}
	stack->head = create_node(ft_atoi(args[i]));
	tmp = stack->head;
	while (++i < arg0)
	{
		tmp->next = create_node(ft_atoi(args[i]));
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (stack);
}

int	stack_len(t_stack *stack)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = stack->head;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
