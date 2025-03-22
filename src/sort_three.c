/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:43:04 by vpogorel          #+#    #+#             */
/*   Updated: 2025/03/19 16:16:40 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

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
	determin_case(stack, num1, num2, num1, s);
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
		rotate(stack, stack->head, s);
	}
	else if (num1 < num2 && num1 < num3 && num2 > num3)
	{
		swap(stack, s);
		rotate(stack, stack->head, s);
	}
}