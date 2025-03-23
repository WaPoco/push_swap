/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:32:55 by vpogorel          #+#    #+#             */
/*   Updated: 2025/03/23 14:17:28 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	check_double(int args0, char **args)
{
	int	i;
	int	j;
	int	num1;
	int	num2;

	i = 1;
	while (i < args0)
	{
		num1 = ft_atoi(args[i]);
		j = i + 1;
		while (j < args0)
		{
			num2 = ft_atoi(args[j]);
			if (num1 == num2)
			{
				ft_printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_min_max(int args0, char **args)
{
	long	num;
	int		i;

	i = 1;
	while (i < args0)
	{
		num = ft_atol(args[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			ft_printf("Error\n");
			exit(1);
		}
		i++;
	}
}

void	empty(char number)
{
	if (!number || number == '\0')
	{
		ft_printf("Error\n");
		exit(1);
	}
}

void	check_numbers(int args0, char **args)
{
	int	i;
	int	j;

	i = 1;
	while (i < args0)
	{
		empty(args[i][0]);
		j = 0;
		while (j < (int)ft_strlen(args[i]))
		{
			if (!ft_isdigit(args[i][j]))
			{
				if (j == 0 && ft_strlen(args[i]) != 1 
					&& (args[i][j] == '-' || args[i][j] == '+'))
				{
					j++;
					continue ;
				}
				ft_printf("Error\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	check_arguments(int args0, char **args)
{
	if (args0 == 1)
		exit(0);
	check_numbers(args0, args);
	check_min_max(args0, args);
	check_double(args0, args);
}
