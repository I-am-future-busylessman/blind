/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 18:28:34 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/05/29 14:20:38 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

list		*ft_lstmap(list *lst, void *(*f)(void *), void (*del)(void *))
{
	list *newlst_res;
	list *newlst_ptr;

	if (!lst)
		return (NULL);
	newlst_res = NULL;
	while (lst)
	{
		if (!(newlst_ptr = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&newlst_res, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst_res, newlst_ptr);
		lst = lst->next;
	}
	return (newlst_res);
}
