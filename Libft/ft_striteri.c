/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:41:12 by vpogorel          #+#    #+#             */
/*   Updated: 2024/11/23 15:42:23 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	len_s;
	size_t	i;

	if (s == NULL || f == NULL)
		return ;
	len_s = ft_strlen((char *)s);
	i = 0;
	while (i < len_s)
	{
		f(i, &s[i]);
		i++;
	}
}
