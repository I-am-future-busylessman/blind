/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 18:25:31 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/05/27 22:17:27 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(list *lst, void (*del)(void
*))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
		lst = NULL;
	}
}
