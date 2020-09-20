/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:46:16 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/05/25 20:26:48 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	len;
	unsigned int	counter;

	counter = 0;
	len = 0;
	while (dst[counter] && counter < size)
		counter++;
	len = counter;
	while (src[counter - len] && counter + 1 < size)
	{
		dst[counter] = src[counter - len];
		counter++;
	}
	if (size > len)
		dst[counter] = '\0';
	return (ft_strlen(src) + len);
}
