/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:06:43 by vpogorel          #+#    #+#             */
/*   Updated: 2024/11/26 10:10:10 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	position;
	int	i;

	i = 0;
	position = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			position = i;
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)(s + i));
	if (s[position] == (unsigned char)c)
		return ((char *)(s + position));
	else
		return (NULL);
}
