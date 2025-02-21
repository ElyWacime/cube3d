/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:56:01 by welyousf          #+#    #+#             */
/*   Updated: 2025/02/21 16:36:34 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;
	void	*var;

	if (f == NULL || del == NULL)
		return (NULL);
	head = NULL;
	while (lst)
	{
		var = f(lst->content);
		new = ft_lstnew(var);
		if (new == NULL)
		{
			del(var);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}
