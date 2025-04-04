/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:44:24 by vpogorel          #+#    #+#             */
/*   Updated: 2025/03/23 13:28:29 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	get_index(t_stack *stack, int number)
{
	int		new_index;
	int		cur_diff;
	int		max_diff;
	int		i;
	t_node	*cur;

	cur = stack->head;
	i = 0;
	cur_diff = cur->number - number;
	max_diff = stack->min - number;
	new_index = stack->index_min;
	if (stack->max - number < 0 || stack->min - number > 0)
		return (stack->index_max);
	while (cur != NULL)
	{
		cur_diff = cur->number - number;
		if (cur_diff < 0 && max_diff < cur_diff)
		{
			max_diff = cur_diff;
			new_index = i;
		}
		cur = cur->next;
		i++;
	}
	return (new_index);
}

int	get_index_in_a(t_stack *stack, int number)
{
	int		new_index;
	int		cur_diff;
	int		max_diff;
	int		i;
	t_node	*cur;

	cur = stack->head;
	i = 0;
	cur_diff = cur->number - number;
	max_diff = stack->max - number;
	new_index = stack->index_max;
	if (stack->max - number < 0 || stack->min - number > 0)
		return (stack->index_min);
	while (cur != NULL)
	{
		cur_diff = cur->number - number;
		if (cur_diff > 0 && max_diff > cur_diff)
		{
			max_diff = cur_diff;
			new_index = i;
		}
		cur = cur->next;
		i++;
	}
	return (new_index);
}

void	cheap_move_a(t_stacks *stacks)
{
	while (stacks->stack_a->move->r-- != 0)
		rotate(stacks->stack_a, stacks->stack_a->head, 'a');
	while (stacks->stack_a->move->rr-- != 0)
		reverse_rotate(stacks->stack_a, 'a');
	while (stacks->stack_b->move->p != 0)
	{
		push(stacks, 'a');
		stacks->stack_b->move->p--;
	}
}

void	move_stack(t_stack *stack, int index)
{
	int	len_stack;

	stack->move->r = 0;
	stack->move->rr = 0;
	len_stack = stack_len(stack);
	if (index < len_stack - index)
		stack->move->r += index;
	else
		stack->move->rr += len_stack - index;
	find_stack_min_max(stack);
}

void	move_back(t_stacks *stacks)
{
	t_node	*head_b;

	head_b = stacks->stack_b->head;
	find_stack_min_max(stacks->stack_b);
	find_stack_min_max(stacks->stack_a);
	while (stacks->stack_b->head != NULL)
	{
		head_b = stacks->stack_b->head;
		find_stack_min_max(stacks->stack_b);
		find_stack_min_max(stacks->stack_a);
		move_stack(stacks->stack_a,
			get_index_in_a(stacks->stack_a, head_b->number));
		stacks->stack_b->move->p = 1;
		cheap_move_a(stacks);
	}
}
