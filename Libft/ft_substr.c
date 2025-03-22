/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:27:42 by vpogorel          #+#    #+#             */
/*   Updated: 2024/11/22 18:55:07 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	end;
	char	*sub;

	if (s == NULL)
		return (NULL);
	if (*s == '\0')
		return (ft_strdup(""));
	else
		len_s = ft_strlen((char *)s);
	if (len == 0 || (size_t)start > len_s - 1)
		return (ft_strdup(""));
	end = len + (size_t)start - 1;
	if (end > len_s - 1)
		end = len_s - 1;
	sub = ft_calloc(end - (size_t)start + 2, sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcat(sub, s + start, end - (size_t)start + 2);
	return (sub);
}
