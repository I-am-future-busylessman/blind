/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:23:49 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/07/28 23:17:23 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
	|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (0);
	return (-1);
}

t_list		ft_init_save(void)
{
	t_list save;

	save.zero = 0;
	save.min = 0;
	save.wd = 0;
	save.prc = 0;
	save.prc_num = 0;
	save.type = 0;
	save.sign = 0;
	return (save);
}

static char	*ft_get_line(long num, int len)
{
	char	*line;
	int		sign;

	if (num != 0)
		line = malloc(sizeof(char) * (len + 1));
	else
		return (line = ft_strdup("0"));
	sign = 0;
	if (num < 0)
	{
		sign++;
		num = -num;
	}
	line[len] = '\0';
	while (--len)
	{
		line[len] = (num % 10) + '0';
		num /= 10;
	}
	if (sign == 1)
		line[0] = '-';
	else
		line[0] = (num % 10) + '0';
	return (line);
}

char		*ft_utoa(unsigned int u)
{
	int		len;
	long	num;

	num = u;
	len = 0;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num >= 1)
	{
		len++;
		num /= 10;
	}
	num = u;
	return (ft_get_line(num, len));
}
