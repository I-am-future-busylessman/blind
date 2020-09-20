/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:47:31 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/05/25 14:47:32 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *source, int c)
{
	char	*last_pos;

	last_pos = (0);
	while (*source)
	{
		if (*source == c)
			last_pos = (char*)source;
		++source;
	}
	if (last_pos)
		return (last_pos);
	if (c == '\0')
		return ((char*)source);
	return (0);
}
