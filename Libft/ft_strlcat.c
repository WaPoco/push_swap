/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:38:19 by vpogorel          #+#    #+#             */
/*   Updated: 2024/11/25 17:12:18 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen((char *)dst);
	len_src = ft_strlen((char *)src);
	if (len_dst > size)
		return (size + len_src);
	if (len_dst + len_src < size)
	{
		ft_memmove(dst + len_dst, src, len_src);
		dst[len_dst + len_src] = '\0';
	}
	else if (size > len_dst + 1)
	{
		ft_memmove(dst + len_dst, src, size - 1 - len_dst);
		dst[size - 1] = '\0';
	}
	return (len_dst + len_src);
}
