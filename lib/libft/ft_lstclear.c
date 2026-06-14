/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 02:12:19 by bpetrovi          #+#    #+#             */
/*   Updated: 2025/04/06 02:54:35 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*current_node;

	node = *lst;
	while (node)
	{
		current_node = node;
		node = node -> next;
		ft_lstdelone(current_node, del);
	}
	*lst = NULL;
}
