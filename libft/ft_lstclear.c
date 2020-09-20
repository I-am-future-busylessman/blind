/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 18:24:53 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/05/27 18:24:58 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(list **lst, void (*del)(void
*))
{
	list *temp_lst;

	if (lst && del)
	{
		while (*lst)
		{
			temp_lst = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = temp_lst;
		}
	}
}
