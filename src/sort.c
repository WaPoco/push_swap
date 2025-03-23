/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:43:04 by vpogorel          #+#    #+#             */
/*   Updated: 2025/03/22 20:06:03 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	sort_two(t_stack *stack, char s)
{
	t_node	*head;
	int			num1;
	int			num2;

	head = stack->head;
	num1 = head->number;
	num2 = head->next->number;
	if (num1 > num2)
		swap(stack, s);
}

void	sort_three(t_stack *stack, char s)
{
	t_node	*head;
	int			num1;
	int			num2;
	int			num3;

	head = stack->head;
	num1 = head->number;
	num2 = head->next->number;
	num3 = head->next->next->number;
	determin_case(stack, num1, num2, num3, s);
}

void	determin_case(t_stack *stack, int num1, int num2, int num3, char s)
{
	if (num1 > num2 && num1 < num3 && num2 < num3)
		swap(stack, s);
	else if (num1 > num2 && num1 > num3 && num2 < num3)
		rotate(stack, stack->head, s);
	else if (num1 < num2 && num1 > num3 && num2 > num3)
		reverseRotate(stack, s);
	else if (num1 > num2 && num1 > num3 && num2 > num3)
	{
		swap(stack, s);
		reverseRotate(stack, s);
	}
	else if (num1 < num2 && num1 < num3 && num2 > num3)
	{
		swap(stack, s);
		rotate(stack, stack->head, s);
	}
	else if (num1 < num2 && num1 > num3 && num2 < num3)
		swap(stack, s);
}

void	sort(t_stacks *stacks)
{
	int	len_stack_a;

	len_stack_a = stack_len(stacks->stack_a);
	if (len_stack_a == 1)
		return (printStack(stacks->stack_a->head));
	else if (len_stack_a == 2)
	{
		sort_two(stacks->stack_a, 'a');
		return (printStack(stacks->stack_a->head));
	}
	else if (len_stack_a == 3)
	{
		sort_three(stacks->stack_a, 'a');
		return (printStack(stacks->stack_a->head));
	}
	if (len_stack_a >= 5)
	{
		push(stacks, 'b');
		push(stacks, 'b');
	}
	else if (len_stack_a >= 4)
		push(stacks, 'b');
	move_cheapest(stacks);
	sort_three(stacks->stack_a, 'a');
	move_back(stacks);
}
