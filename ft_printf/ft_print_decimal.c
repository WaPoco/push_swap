/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:58:47 by vpogorel          #+#    #+#             */
/*   Updated: 2024/12/05 16:53:33 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_digit(int fd, long n, int sign, int *count)
{
	char	digit;

	if (n == 0)
	{
		if (sign == -1)
		{
			write(fd, "-", 1);
			(*count)++;
		}
		return ;
	}
	print_digit(fd, n / 10, sign, count);
	digit = (n % 10) + '0';
	write(fd, &digit, 1);
	(*count)++;
}

void	ft_putnbr_fd(int n, int fd, int *count)
{
	if (n < 0)
		print_digit(fd, -(long)n, -1, count);
	else if (n == 0)
	{
		write(fd, "0", 1);
		(*count)++;
	}
	else
		print_digit(fd, n, 1, count);
}

void	ft_print_decimal(va_list args, int *count)
{
	int	result;

	result = va_arg(args, int);
	ft_putnbr_fd(result, 1, count);
}
