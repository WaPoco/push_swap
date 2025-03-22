/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:37:08 by vpogorel          #+#    #+#             */
/*   Updated: 2024/11/25 17:02:03 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	k;

	k = 0;
	if (n == 0)
		return (0);
	while ((s1[k] || s2[k]) && k < n)
	{
		if (s1[k] != s2[k])
			return ((unsigned char)s1[k] - (unsigned char)s2[k]);
		k++;
	}
	return (0);
}
