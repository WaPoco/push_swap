/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:36:51 by vpogorel          #+#    #+#             */
/*   Updated: 2024/12/05 17:12:02 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flag(va_list args, char flag, int *count)
{
	if (flag == 'c')
		ft_print_char(args, count);
	else if (flag == 's')
		ft_print_string(args, count);
	else if (flag == 'p')
		ft_print_pointer(args, count);
	else if (flag == 'd' || flag == 'i')
		ft_print_decimal(args, count);
	else if (flag == 'u')
		ft_print_udecimal(args, count);
	else if (flag == 'x')
		ft_print_number_hex(args, 'l', count);
	else if (flag == 'X')
		ft_print_number_hex(args, 'u', count);
	else if (flag == '%')
		ft_print_percent(count);
}
