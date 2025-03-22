/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:48:04 by vpogorel          #+#    #+#             */
/*   Updated: 2024/11/24 22:58:08 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t			len_s;
	char			*dup;

	len_s = ft_strlen((char *)s);
	dup = (char *)malloc(len_s + 1);
	if (!dup)
		return (NULL);
	ft_memmove(dup, s, len_s);
	dup[len_s] = '\0';
	return (dup);
}
