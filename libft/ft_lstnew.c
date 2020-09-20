/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 18:28:48 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/05/27 18:28:53 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

list		*ft_lstnew(void *content)
{
	list *list;

	list = NULL;
	list = malloc(sizeof(list));
	if (list)
	{
		list->content = content;
		list->next = NULL;
	}
	return (list);
}
