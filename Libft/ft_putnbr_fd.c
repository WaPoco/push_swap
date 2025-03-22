/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:13:17 by vpogorel          #+#    #+#             */
/*   Updated: 2024/11/24 12:01:47 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_digit(int fd, long n, int sign)
{
	char	digit;

	if (n == 0)
	{
		if (sign == -1)
			write(fd, "-", 1);
		return ;
	}
	print_digit(fd, n / 10, sign);
	digit = (n % 10) + '0';
	write(fd, &digit, 1);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		print_digit(fd, -(long)n, -1);
	else if (n == 0)
		write(fd, "0", 1);
	else
		print_digit(fd, (long)n, 1);
}
