/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:30:30 by vpogorel          #+#    #+#             */
/*   Updated: 2025/03/12 20:14:02 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	new_num_in_stack_b(t_stacks *stacks, t_node *head_a)
{
	int	index;
	int	number_b;
	int	number_a;
	t_node	*head_b;
	int	position_b;

	position_b = stack_len(stacks->stack_b);
	number_a = head_a->number;
	number_b = stacks->stack_b->head->number;
	head_b = stacks->stack_b->head;
	position_b = 0;
	while (head_b != NULL && number_a < number_b)
	{
		index++;
		head_b = head_b->next;
		number_b = head_b->number;
	}
	if (index - 1 >= position_b - (index - 1))
		stacks->stack_b->cheapest->rrb += index - 1;
	else
		stacks->stack_b->cheapest->rb += position_b - (index - 1);
}

void	check_cost(stacks, i)
{
	
}

void	new_max_or_min_stack_b(t_stack *stack_b, int number)
{
	if (stack_b->max < number)	
		stack_b->cheapest->pb++;
	if (stack_b->min > number)
	{
		stack_b->cheapest->pb++;
		stack_b->cheapest->rb++;
	}
}

int		find_stack_min_max(t_stack *stack)
{
	t_node	*temp;
	
	temp = stack->head->next;
	stack->min = stack->head->number;
	stack->max = stack->head->number;
    while (temp != NULL)
	{
        if (temp->number < stack->min)
			stack->min= temp->number;
        if (temp->number > stack->max)
			stack->max = temp->number;
        temp = stack->head->next;
    }
}

void	check_moves(t_stacks *stacks)
{
	int			i;
	int			size_b;
	t_node      *head_a;

	head_a = stacks->stack_a->head;
	size_b = stack_len(stacks->stack_b);
	find_stack_min_max(stacks->stack_b);
	i = 0;
	while (i++ < size_b)
	{
		if (head_a->number > stacks->stack_b->max || head_a->number < stacks->stack_b->min)
			new_max_or_min_stack_b(stacks->stack_b, head_a->number);
		else
			new_num_in_stack_b(stacks, head_a->number);
		//check_double_moves(stack);
		check_cost(stacks, i);
		head_a = head_a->next;
	}
}

void	move_cheapest(t_stacks *stacks)
{
	while (stack_len != 3)
	{
		check_moves(stacks);
		do_cheap_moves(stacks);
	}
}

