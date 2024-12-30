/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:51:47 by skamroun          #+#    #+#             */
/*   Updated: 2023/12/22 21:20:41 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;

	if (lst != NULL && del != NULL)
	{
		while ((*lst) != NULL)
		{
			p = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			(*lst) = p;
		}
	}
}
