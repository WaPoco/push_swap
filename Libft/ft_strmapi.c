/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:29:19 by vpogorel          #+#    #+#             */
/*   Updated: 2024/11/24 12:20:35 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char ))
{
	size_t	len_s;
	char	*new_s;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	len_s = ft_strlen((char *)s);
	new_s = malloc(len_s + 1);
	i = 0;
	if (!new_s)
		return (NULL);
	while (i < len_s)
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	new_s[len_s] = '\0';
	return (new_s);
}
