/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:02:55 by vpogorel          #+#    #+#             */
/*   Updated: 2024/12/05 17:11:00 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	get_hex_digit(unsigned int digit, char c)
{
	char	*digit_hex;

	if (c == 'u')
		digit_hex = "0123456789ABCDEF";
	else
		digit_hex = "0123456789abcdef";
	return (digit_hex[digit]);
}

static void	print_hex(unsigned int n, char c, int *count)
{
	char	digit;

	if (n == 0)
		return ;
	print_hex(n / 16, c, count);
	digit = get_hex_digit(n % 16, c);
	write(1, &digit, 1);
	(*count)++;
}

void	ft_print_number_hex(va_list args, char c, int *count)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	if (n == 0)
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	print_hex(n, c, count);
}
