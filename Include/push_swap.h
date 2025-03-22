/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:31:14 by vpogorel          #+#    #+#             */
/*   Updated: 2025/03/22 17:04:34 by vpogorel         ###   ########.fr       */
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
	int					s;
	int					ss;
	int					p;
	int					r;
	int					both_r;
	int					rr;
	int					both_rr;
} t_move;

typedef struct cheapest
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
	t_move 		*move;
	int			min;
	int			index_min;
	int			max;
	int			index_max;
} t_stack;

typedef struct	Stacks
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_moves	*cheapest;
} t_stacks;

// initialize & create stack
void	initializeStack(t_stack *stack);
t_node	*createNode(int number);
t_stack	*createStack(int arg0, char **args);
void	printStack(t_node *currentNode);
void	init_moves(t_stacks *stacks);


// oparations with stack
void	rotate(t_stack *stack, t_node *currentNode, char s);
void	reverseRotate(t_stack *stack, char s);
void	swap(t_stack *stack, char s);
void	pop(t_stack *a);
void	push(t_stacks *stacks, char dstack);
int		stack_len(t_stack *stack);
void		find_stack_min_max(t_stack *stack);
void	move_cheapest(t_stacks *stacks);

// sort three
void	determin_case(t_stack *stack, int num1, int num2, int num3, char s);
void	sort(t_stacks *stacks);

//check arguments for errors
void	check_arguments(int args0, char **args);
void	sort_three(t_stack *stack, char s);

// move stacks
void	move_stack(t_stack *stack, int index);
int		get_index(t_stack *stack, int number);
int		get_index_in_a(t_stack *stack, int number);
void 	move_back(t_stacks *stacks);
void	cheap_move_a(t_stacks *stacks);

// cost
void	check_cost(t_stacks *stacks, int i);
void	cheap_move(t_stacks *stacks);


