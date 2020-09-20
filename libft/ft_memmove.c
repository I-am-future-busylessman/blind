/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:44:02 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/05/27 17:07:01 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t len)
{
	unsigned char *dest;
	unsigned char *src;

	if (!(destination || source))
		return (NULL);
	dest = (unsigned char *)destination;
	src = (unsigned char *)source;
	if (dest < src)
		while (len--)
			*dest++ = *src++;
	else
	{
		dest += len;
		src += len;
		while (len--)
			*--dest = *--src;
	}
	return (destination);
}
