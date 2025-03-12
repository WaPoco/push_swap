/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:31:14 by vpogorel          #+#    #+#             */
/*   Updated: 2025/03/12 12:12:59 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../Libft/libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int number;
	struct Node	*next;
} t_node;

typedef struct Move
{
	int					cost;
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
} t_moves;

typedef struct Stack
{
	t_node		*head;
	t_moves 	*cheapest;
	int	min;
	int	max;
} t_stack;

typedef struct	Stacks
{
	t_stack	*stack_a;
	t_stack	*stack_b;	
} t_stacks;

// initialize & create stack
void	initializeStack(t_stack *stack);
t_node	*createNode(int number);
t_stack	*createStack(int arg0, char **args);
void	printStack(t_node *currentNode);

// oparations with stack
void	rotate(t_stack *stack, t_node *currentNode);
void	reverseRotate(t_stack *stack);
void	swap(t_stack *stack);
void	pop(t_stack *a);
void	push(t_stacks *stacks, char dstack);
int		stack_len(t_stack *stack);
int		find_stack_min_max(t_stack *stack);
void	move_cheapest(t_stacks *stacks);

// sort three
void	determin_case(t_stack *stack, int num1, int num2, int num3);
void	sort(t_stacks *stacks);

//check arguments for errors
void	check_arguments(int args0, char **args);
void	sort_three(t_stack *stack);



