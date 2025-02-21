/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:39:20 by welyousf          #+#    #+#             */
/*   Updated: 2025/02/21 16:36:34 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!new)
		return ;
	else if (!lst)
		return ;
	else if (*lst == NULL)
		*lst = new;
	else
	{
		node = ft_lstlast(*lst);
		node->next = new;
	}
}
