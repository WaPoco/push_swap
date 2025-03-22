/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:16:10 by vpogorel          #+#    #+#             */
/*   Updated: 2024/11/21 16:42:23 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_src;

	len_src = ft_strlen((char *)src);
	if (size == 0)
		return (len_src);
	if (len_src <= size - 1)
	{
		ft_memmove(dst, src, len_src);
		dst[len_src] = '\0';
	}
	else
	{
		ft_memmove(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (len_src);
}
