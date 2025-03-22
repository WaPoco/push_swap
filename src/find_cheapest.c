/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:30:30 by vpogorel          #+#    #+#             */
/*   Updated: 2025/03/22 13:08:57 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	get_index(t_stack *stack, int number)
{
	int	new_index;
	int	cur_diff;
	int	max_diff;
	int	i;
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
		reverseRotate(stacks->stack_a, 'a');
	while (stacks->cheapest->rrb-- != 0)
		reverseRotate(stacks->stack_b, 'b');
	while (stacks->cheapest->rrr-- != 0)
	{
		reverseRotate(stacks->stack_a, 't');
		reverseRotate(stacks->stack_b, 't');
		ft_printf("rrr\n");
	}
	while (stacks->cheapest->pb-- != 0)
		push(stacks, 'b');
	//printStack(stacks->stack_a->head);
	//printf("\n");
	//printStack(stacks->stack_b->head);	
}

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
/*
static void	print_cost(t_stacks *stacks)
{
	printf("Stack A \n");
	printf("p=%d \n", stacks->stack_a->move->p);
	printf("r=%d \n", stacks->stack_a->move->r);	
	printf("rr=%d \n", stacks->stack_a->move->rr);	
	printf("beide r=%d\n", stacks->stack_a->move->both_r);
	printf("beide rr=%d\n", stacks->stack_a->move->both_rr);
	printf("cost=%d\n", stacks->stack_a->move->cost);
	printf("Stack B \n");
	printf("p=%d \n", stacks->stack_b->move->p);
	printf("r=%d \n", stacks->stack_b->move->r);	
	printf("rr=%d \n", stacks->stack_b->move->rr);	
	printf("beide r=%d\n", stacks->stack_b->move->both_r);
	printf("beide rr=%d\n", stacks->stack_b->move->both_rr);
	printf("cost=%d\n", stacks->stack_b->move->cost);
	printf("\n");
}*/

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
	//print_cost(stacks);
}

void		find_stack_min_max(t_stack *stack)
{
	t_node	*temp;
	int		index;
	
	if (stack->head == NULL)
		return ;
	index = 0;
	temp = stack->head;
	stack->min = temp->number;
	stack->max = temp->number;
    while (temp != NULL)
	{
        if (temp->number <= stack->min)
		{
			stack->min = temp->number;
			stack->index_min = index;
		}
        if (temp->number >= stack->max)
		{
			stack->max = temp->number;
			stack->index_max = index;	
		}
		temp = temp->next;
		index++;
	}
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
	//printf("stack_a  rr = %d stack_b  rr = %d \n", stacks->stack_a->move->rr, stacks->stack_b->move->rr);
	while (stacks->stack_a->move->rr >= 1 && stacks->stack_b->move->rr >= 1)
	{
		stacks->stack_a->move->rr--;
		stacks->stack_b->move->rr--;
		stacks->stack_a->move->both_rr++;
		//printf("dsfsd");
	}
}

void	check_moves(t_stacks *stacks)
{
	int			i;
	int			size_a;
	t_node      *head_a;

	head_a = stacks->stack_a->head;
	size_a = stack_len(stacks->stack_a);
	find_stack_min_max(stacks->stack_b);
	find_stack_min_max(stacks->stack_a);
	i = 0;
	while (i < size_a)
	{
		//printf(" number a=%d\n", head_a->number);
		move_stack(stacks->stack_a, i);
		move_stack(stacks->stack_b, get_index(stacks->stack_b, head_a->number));
		//printf(" number a i = %d index = %d max = %d \n", i,  get_index(stacks->stack_b, head_a->number), stacks->stack_b->max);
		check_double_moves(stacks);
		stacks->stack_a->move->p = 1;
		check_cost(stacks, i);
		int total = stacks->stack_a->move->cost + stacks->stack_b->move->cost;
		//printf("i = %d cost %d  cost_a = %d cost_b = %d \n", i, total, stacks->stack_a->move->cost, stacks->stack_b->move->cost);
		//printf(" stack b  rb=%d rrb=%d \n", stacks->cheapest->rb, stacks->cheapest->rrb);
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
		//printStack(stacks->stack_a->head);
		//printf("\n");
		//printStack(stacks->stack_b->head);		
	}
}

