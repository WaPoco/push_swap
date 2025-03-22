/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:52:35 by vpogorel          #+#    #+#             */
/*   Updated: 2024/11/21 15:57:11 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	temp(unsigned char *temp_dest, unsigned char *temp_src, size_t n)
{
	size_t	i;

	i = 0;
	if (temp_dest < temp_src)
	{
		while (i < n)
		{
			temp_dest[i] = temp_src[i];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			temp_dest[n - 1 - i] = temp_src[n - 1 - i];
			i++;
		}
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dest;

	if (!dest && !src)
		return (dest);
	temp_src = (unsigned char *)src;
	temp_dest = (unsigned char *)dest;
	temp(temp_dest, temp_src, n);
	return (dest);
}
