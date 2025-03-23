/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:36:44 by vpogorel          #+#    #+#             */
/*   Updated: 2025/03/23 12:51:45 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	calc_cost(t_stack *stack, char s)
{
	if (s == 'a')
		stack->move->cost = stack->move->p;
	else
		stack->move->cost = 0;
	stack->move->cost += stack->move->r;
	stack->move->cost += stack->move->rr;
	stack->move->cost += stack->move->s;
	stack->move->cost += stack->move->ss;
	if (s == 'a')
	{
		stack->move->cost += stack->move->both_r;
		stack->move->cost += stack->move->both_rr;
	}
}

void	check_cost(t_stacks *stacks, int i)
{
	int	total_cost;

	calc_cost(stacks->stack_a, 'a');
	calc_cost(stacks->stack_b, 'b');
	total_cost = stacks->stack_a->move->cost + stacks->stack_b->move->cost;
	if (i == 0 || stacks->cheapest->cost > total_cost)
	{
		stacks->cheapest->pb = 1;
		stacks->cheapest->ra = stacks->stack_a->move->r;
		stacks->cheapest->rb = stacks->stack_b->move->r;
		stacks->cheapest->rra = stacks->stack_a->move->rr;
		stacks->cheapest->rrb = stacks->stack_b->move->rr;
		stacks->cheapest->rr = stacks->stack_a->move->both_r;
		stacks->cheapest->rrr = stacks->stack_a->move->both_rr;
		stacks->cheapest->cost = total_cost;
	}
}
