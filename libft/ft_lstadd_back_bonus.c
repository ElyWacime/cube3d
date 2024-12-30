/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:40:49 by skamroun          #+#    #+#             */
/*   Updated: 2023/12/19 09:40:51 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	if (lst != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			head = *lst;
			while ((head)->next != NULL)
				head = (head)->next;
			(head)->next = new;
		}
	}
}
