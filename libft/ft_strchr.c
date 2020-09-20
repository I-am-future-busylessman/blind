/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:51:17 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/05/25 23:57:30 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char		*ptr;
	int			counter;

	counter = 0;
	ptr = (char *)s;
	while (ptr[counter] != c)
	{
		if (ptr[counter] == '\0')
			return (0);
		counter++;
	}
	return (ptr + counter);
}
