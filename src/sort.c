/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:43:04 by vpogorel          #+#    #+#             */
/*   Updated: 2025/03/10 11:57:59 by vpogorel         ###   ########.fr       */
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

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	len_stack_a;

	(void)stack_b;
	len_stack_a = stack_len(stack_a);
	if (len_stack_a == 1)
		return ;
	else if (len_stack_a == 2)
		sort_two(stack_a);
	else if (len_stack_a == 3)
		sort_three(stack_a);
	push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
	//move_cheapest(stack_a, stack_b);
	//sort_three(stack_a);
	//move_stack_a(stack_a, stack_b);
}
