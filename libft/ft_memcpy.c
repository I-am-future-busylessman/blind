/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:50:31 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/05/27 18:32:00 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;

	if (!(destination || source))
		return (NULL);
	dest = (unsigned char*)destination;
	src = (unsigned char*)source;
	while (n--)
		*dest++ = *src++;
	return (destination);
}
