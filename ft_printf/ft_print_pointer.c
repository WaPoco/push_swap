/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:03:01 by vpogorel          #+#    #+#             */
/*   Updated: 2024/12/05 17:09:07 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	get_hex_digit(int digit)
{
	char	*digit_hex;

	digit_hex = "0123456789abcdef";
	return (digit_hex[digit]);
}

static void	print_hex(unsigned long long n, int *count)
{
	char	digit;

	if (n == 0)
		return ;
	print_hex(n / 16, count);
	digit = get_hex_digit(n % 16);
	write(1, &digit, 1);
	(*count)++;
}

static void	ft_print_pointer_hex(unsigned long long n, int *count)
{
	print_hex(n, count);
	if (n == 0)
	{
		write(1, "0", 1);
		(*count)++;
	}
}

void	ft_print_pointer(va_list args, int *count)
{
	unsigned long long	number_pointer;

	number_pointer = (unsigned long long)(va_arg(args, void *));
	if (number_pointer == 0)
	{
		write(1, "(nil)", 5);
		(*count) += 5;
		return ;
	}
	write(1, "0x", 2);
	(*count) += 2;
	ft_print_pointer_hex(number_pointer, count);
}
