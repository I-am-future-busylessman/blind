/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:42:37 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/05/27 17:10:45 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int num)
{
	int				count;
	unsigned int	n;

	if (num == 0)
		return (1);
	count = 0;
	n = num <= 0 ? -num : num;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				len;
	int				sign;
	unsigned long	num;

	sign = (n < 0) ? 1 : 0;
	num = n;
	len = count(num);
	if (!(str = (char*)malloc(sizeof(char) * (len + sign + 1))))
		return (NULL);
	str[len + sign] = '\0';
	if (sign == 1)
	{
		str[0] = '-';
		num = -num;
		len++;
	}
	len--;
	while (len >= sign)
	{
		str[len] = num % 10 + '0';
		num /= 10;
		len--;
	}
	return (str);
}
