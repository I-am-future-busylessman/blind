/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:50:56 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/05/25 16:16:31 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t len)
{
	unsigned char	*place;
	unsigned char	symb;

	place = (unsigned char*)destination;
	symb = (unsigned char)c;
	while (len--)
		*place++ = symb;
	return (destination);
}
