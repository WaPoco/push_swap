/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_udecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:00:59 by vpogorel          #+#    #+#             */
/*   Updated: 2024/12/05 20:19:27 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_digit(unsigned int n, int sign, int *count)
{
	char	digit;

	if (n == 0)
		return ;
	print_digit(n / 10, sign, count);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
	(*count)++;
	return ;
}

void	ft_print_udecimal(va_list args, int *count)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	print_digit(n, 1, count);
	if (n == 0)
	{
		write(1, "0", 1);
		(*count)++;
	}
}
