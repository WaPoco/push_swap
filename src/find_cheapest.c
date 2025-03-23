/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:30:30 by vpogorel          #+#    #+#             */
/*   Updated: 2025/03/23 13:28:19 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	cheap_move(t_stacks *stacks)
{
	while (stacks->cheapest->ra-- != 0)
		rotate(stacks->stack_a, stacks->stack_a->head, 'a');
	while (stacks->cheapest->rb-- != 0)
		rotate(stacks->stack_b, stacks->stack_b->head, 'b');
	while (stacks->cheapest->rr-- != 0)
	{
		rotate(stacks->stack_b, stacks->stack_b->head, 't');
		rotate(stacks->stack_a, stacks->stack_a->head, 't');
		ft_printf("rr\n");
	}
	while (stacks->cheapest->rra-- != 0)
		reverse_rotate(stacks->stack_a, 'a');
	while (stacks->cheapest->rrb-- != 0)
		reverse_rotate(stacks->stack_b, 'b');
	while (stacks->cheapest->rrr-- != 0)
	{
		reverse_rotate(stacks->stack_a, 't');
		reverse_rotate(stacks->stack_b, 't');
		ft_printf("rrr\n");
	}
	while (stacks->cheapest->pb-- != 0)
		push(stacks, 'b');
}

void	check_double_moves(t_stacks *stacks)
{
	stacks->stack_a->move->both_r = 0;
	stacks->stack_a->move->both_rr = 0;
	while (stacks->stack_a->move->r >= 1 && stacks->stack_b->move->r >= 1)
	{
		stacks->stack_a->move->r--;
		stacks->stack_b->move->r--;
		stacks->stack_a->move->both_r++;
	}
	while (stacks->stack_a->move->rr >= 1 && stacks->stack_b->move->rr >= 1)
	{
		stacks->stack_a->move->rr--;
		stacks->stack_b->move->rr--;
		stacks->stack_a->move->both_rr++;
	}
}

void	check_moves(t_stacks *stacks)
{
	int			i;
	int			size_a;
	t_node		*head_a;
	int			total;

	head_a = stacks->stack_a->head;
	size_a = stack_len(stacks->stack_a);
	find_stack_min_max(stacks->stack_b);
	find_stack_min_max(stacks->stack_a);
	i = 0;
	while (i < size_a)
	{
		move_stack(stacks->stack_a, i);
		move_stack(stacks->stack_b, get_index(stacks->stack_b, head_a->number));
		check_double_moves(stacks);
		stacks->stack_a->move->p = 1;
		check_cost(stacks, i);
		total = stacks->stack_a->move->cost + stacks->stack_b->move->cost;
		if (total == 1 || (total == 2 && i == 0))
			return ;
		head_a = head_a->next;
		i++;
	}
}

void	move_cheapest(t_stacks *stacks)
{
	while (stack_len(stacks->stack_a) != 3)
	{
		check_moves(stacks);
		cheap_move(stacks);
	}
}
