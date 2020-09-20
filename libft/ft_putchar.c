/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:21:16 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/07/28 23:28:02 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putcharl(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int		ft_putstrl(char *s)
{
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
