/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:43:04 by vpogorel          #+#    #+#             */
/*   Updated: 2025/03/23 13:28:42 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	sort_two(t_stack *stack, char s)
{
	t_node		*head;
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
	determin_case(stack, s);
}

void	determin_case(t_stack *stack, char s)
{
	int			num1;
	int			num2;
	int			num3;

	num1 = stack->head->number;
	num2 = stack->head->next->number;
	num3 = stack->head->next->next->number;
	if (num1 > num2 && num1 < num3 && num2 < num3)
		swap(stack, s);
	else if (num1 > num2 && num1 > num3 && num2 < num3)
		rotate(stack, stack->head, s);
	else if (num1 < num2 && num1 > num3 && num2 > num3)
		reverse_rotate(stack, s);
	else if (num1 > num2 && num1 > num3 && num2 > num3)
	{
		swap(stack, s);
		reverse_rotate(stack, s);
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
		return ;
	else if (len_stack_a == 2)
	{
		sort_two(stacks->stack_a, 'a');
		return ;
	}
	else if (len_stack_a == 3)
	{
		sort_three(stacks->stack_a, 'a');
		return ;
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
