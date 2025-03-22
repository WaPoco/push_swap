/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:00:39 by vpogorel          #+#    #+#             */
/*   Updated: 2024/11/24 12:31:25 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	long_max_limit(unsigned long long result,
const char *str, unsigned long long i, int sign)
{
	unsigned long long	temp;

	temp = 10 * result + (str[i] - '0');
	if ((sign == -1)
		&& (temp == (unsigned long long)(LONG_MAX) + 1))
		return (LONG_MIN);
	else if (temp > (unsigned long long)(LONG_MAX))
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	unsigned long long	i;
	unsigned long long	sign;
	int					limit;

	result = 0;
	sign = 1;
	i = 0;
	limit = 1;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		limit = long_max_limit(result, str, i, (int)sign);
		if (limit == -1 || limit == 0)
			return (limit);
		result = 10 * result + (str[i++] - '0');
	}
	return (sign * result);
}
