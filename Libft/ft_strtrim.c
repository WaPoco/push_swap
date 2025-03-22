/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:26:52 by vpogorel          #+#    #+#             */
/*   Updated: 2024/11/24 12:25:15 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_s1;
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (*s1 == '\0')
		return (ft_strdup(s1));
	start = 0;
	len_s1 = ft_strlen((char *)s1);
	end = len_s1 - 1;
	while (is_in_set(s1[start], set) == 1)
		start++;
	while (is_in_set(s1[end], set) == 1)
		end--;
	if (start > end)
		return (ft_strdup(""));
	return (ft_substr(s1, (unsigned int)start, end - start + 1));
}
