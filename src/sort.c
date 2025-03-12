/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:43:04 by vpogorel          #+#    #+#             */
/*   Updated: 2025/03/12 20:14:09 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	sort_two(t_stack *stack)
{
	t_node	*head;
	int			num1;
	int			num2;

	head = stack->head;
	num1 = head->number;
	num2 = head->next->number;
	if (num1 > num2)
		swap(stack);
}

void	sort_three(t_stack *stack)
{
	t_node	*head;
	int			num1;
	int			num2;
	int			num3;

	head = stack->head;
	num1 = head->number;
	num2 = head->next->number;
	num3 = head->next->next->number;
	determin_case(stack, num1, num2, num3);
}

void	determin_case(t_stack *stack, int num1, int num2, int num3)
{
	if (num1 > num2 && num1 < num3 && num2 < num3)
		swap(stack);
	else if (num1 > num2 && num1 > num3 && num2 < num3)
		rotate(stack, stack->head);
	else if (num1 < num2 && num1 > num3 && num2 > num3)
		reverseRotate(stack);
	else if (num1 > num2 && num1 > num3 && num2 > num3)
	{
		swap(stack);
		rotate(stack, stack->head);
	}
	else if (num1 < num2 && num1 < num3 && num2 > num3)
	{
		swap(stack);
		rotate(stack, stack->head);
	}
}

void	sort(t_stacks *stacks)
{
	int	len_stack_a;

	len_stack_a = stack_len(stacks->stack_a);
	if (len_stack_a == 1)
		return ;
	else if (len_stack_a == 2)
		sort_two(stacks->stack_a);
	else if (len_stack_a == 3)
		sort_three(stacks->stack_a);
	push(stacks, 'b');
	push(stacks, 'b');
	move_cheapest(stacks);
	sort_three(stacks->stack_a);
	move_stack_a(stacks);
}
