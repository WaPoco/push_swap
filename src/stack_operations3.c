/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:26:06 by vpogorel          #+#    #+#             */
/*   Updated: 2025/03/23 13:33:02 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	swap(t_stack *stack, char s)
{
	int		temp;
	t_node	*next;

	next = stack->head->next;
	if (stack->head == NULL || next == NULL)
		return ;
	temp = stack->head->number;
	stack->head->number = next->number;
	next->number = temp;
	ft_printf("s%c\n", s);
}
