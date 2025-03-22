/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:41:25 by vpogorel          #+#    #+#             */
/*   Updated: 2024/11/20 20:41:01 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n > 0 || n < 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	get_str(char *number, long n, int len)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		number[0] = '0';
		return ;
	}
	if (n < 0)
	{
		number[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		number[len - 1 - i++] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*number;
	int		len;

	len = count_digits(n);
	number = malloc(len + 1);
	if (!number)
		return (NULL);
	get_str(number, (long)n, len);
	number[len] = '\0';
	return (number);
}
