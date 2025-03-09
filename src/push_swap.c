/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:00:25 by vpogorel          #+#    #+#             */
/*   Updated: 2025/03/09 20:22:28 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	main(int args0, char **args)
{
	check_arguments(args0, args);
	t_stack *stack_a = createStack(args0, args);
	//t_stack *stack_b = createStack(0, NULL);
	sort_three(stack_a);
	printStack(stack_a->head);
	free(stack_a);
	return (0);
}
