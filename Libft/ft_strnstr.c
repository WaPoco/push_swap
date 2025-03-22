/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:20:38 by vpogorel          #+#    #+#             */
/*   Updated: 2024/11/26 11:48:44 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_big;
	size_t	len_little;

	i = 0;
	len_big = ft_strlen((char *)big);
	len_little = ft_strlen((char *)little);
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && i < len_big)
	{
		j = 0;
		while (i + j < len && i + j < len_big
			&& j < len_little && big[i + j] == little[j])
			j++;
		if (j == len_little)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
