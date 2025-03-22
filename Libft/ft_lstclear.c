/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:58:47 by vpogorel          #+#    #+#             */
/*   Updated: 2024/11/24 21:49:31 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*last;
	t_list	*current;

	current = *lst;
	while (current)
	{
		last = current;
		current = current->next;
		ft_lstdelone(last, del);
	}
	*lst = NULL;
}
