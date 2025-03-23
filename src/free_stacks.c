/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:42:10 by vpogorel          #+#    #+#             */
/*   Updated: 2025/03/23 12:24:34 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	free_stack(t_stack *stack, t_node *cur)
{
	if (cur == NULL)
		return ;
	free_stack(stack, cur->next);
	free(cur);
}

void	free_all(t_stacks *stacks)
{
	free_stack(stacks->stack_a, stacks->stack_a->head);
	free_stack(stacks->stack_b, stacks->stack_b->head);
	free(stacks->cheapest);
	free(stacks->stack_a->move);
	free(stacks->stack_a);
	free(stacks->stack_b->move);
	free(stacks->stack_b);
	free(stacks);
}
