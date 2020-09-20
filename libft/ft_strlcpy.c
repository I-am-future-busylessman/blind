/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:46:31 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/05/27 18:34:08 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlcpy(char *dest, const char *source, size_t n)
{
	unsigned int	i;
	size_t			size;

	if (!dest && !source)
		return (0);
	i = 0;
	size = ft_strlen(source);
	if (n == 0)
		return (size);
	while (source[i] && (i < (n - 1)))
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (size);
}
