/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:53:59 by vpogorel          #+#    #+#             */
/*   Updated: 2024/11/22 19:19:56 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	res = malloc(len_s1 + len_s2 + 1);
	if (!res)
		return (NULL);
	ft_memmove(res, s1, len_s1);
	ft_memmove(res + len_s1, s2, len_s2);
	res[len_s1 + len_s2] = '\0';
	return (res);
}
