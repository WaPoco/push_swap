/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:08:13 by vpogorel          #+#    #+#             */
/*   Updated: 2024/11/25 20:45:25 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	value;

	i = 0;
	p = (unsigned char *)s;
	value = (unsigned char)c;
	if (n == 0)
		return (NULL);
	while (p[i] != value && (i + 1 < n))
		i++;
	if (p[i] == value)
		return ((void *)(p + i));
	else
		return (NULL);
}
