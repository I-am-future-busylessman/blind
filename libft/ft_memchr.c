/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:43:20 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/05/25 16:12:23 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char *src;
	unsigned char symbol;

	src = (unsigned char *)arr;
	symbol = (unsigned char)c;
	while (n--)
	{
		if (*src == symbol)
			return (src);
		src++;
	}
	return (NULL);
}
