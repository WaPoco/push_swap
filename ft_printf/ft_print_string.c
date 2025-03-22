/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:59:29 by vpogorel          #+#    #+#             */
/*   Updated: 2024/12/05 17:09:38 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putstr_fd(char *s, int fd, int *count)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	(*count) += i;
}

void	ft_print_string(va_list args, int *count)
{
	char	*result;

	result = va_arg(args, char *);
	if (result == NULL)
	{
		write(1, "(null)", 6);
		(*count) += 6;
		return ;
	}
	ft_putstr_fd(result, 1, count);
}
