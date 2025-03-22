/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:00:25 by vpogorel          #+#    #+#             */
/*   Updated: 2025/03/22 18:10:26 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	init_moves(t_stacks *stacks)
{
	stacks->stack_a->move = ft_calloc(1, sizeof(t_move));
	stacks->stack_b->move = ft_calloc(1, sizeof(t_move));
	stacks->cheapest = ft_calloc(1, sizeof(t_moves));
}

void	init_stacks_min_max(t_stacks *stacks)
{
	find_stack_min_max(stacks->stack_a);
	find_stack_min_max(stacks->stack_b);
}

t_stacks	*init_stacks(int args0, char **args)
{
	t_stack 	*stack_a;
	t_stack 	*stack_b;
	t_stacks	*stacks;
	
	stack_a = createStack(args0, args);
	stack_b = createStack(1, NULL);
	stacks = (t_stacks*)malloc(sizeof(t_stacks));
	if (!stacks)
	{
		free(stack_a);
		free(stack_b);
		exit(1);
	}
	stacks->stack_a = stack_a;
	stacks->stack_b = stack_b;
	init_stacks_min_max(stacks);
	init_moves(stacks);
	return (stacks);
}

int	main(int args0, char **args)
{
	t_stacks	*stacks;
	
	check_arguments(args0, args);
	stacks = init_stacks(args0, args);
	sort(stacks);
	find_stack_min_max(stacks->stack_b);
	find_stack_min_max(stacks->stack_a);
	move_stack(stacks->stack_a, get_index_in_a(stacks->stack_a, stacks->stack_a->min) - 1);
	cheap_move_a(stacks);
	//printStack(stacks->stack_a->head);
	//printStack(stacks->stack_b->head);
	free(stacks->cheapest);
	free(stacks->stack_a->move);
	free(stacks->stack_b->move);
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks);
	return (0);
}
