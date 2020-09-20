/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:43:07 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/05/25 20:13:59 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	unsigned char	symb;

	dest = (unsigned char*)destination;
	src = (unsigned char*)source;
	symb = (unsigned char)c;
	while (n--)
	{
		*dest++ = *src++;
		if (*(dest - 1) == symb)
			return (dest);
	}
	return (NULL);
}
