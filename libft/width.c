/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:28:54 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/07/28 22:28:57 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_treat_wd(char *line, int i, t_list *save)
{
	int		width;
	int		sym;
	int		len;
	int		j;

	j = 0;
	len = 0;
	width = save->wd;
	width -= i;
	if (save->zero == 1)
		sym = '0';
	else
		sym = ' ';
	while (width-- != 0 && save->min == 0)
		len += ft_putcharl(sym);
	while (i-- != 0 && line)
		len += ft_putcharl(line[j++]);
	while (width-- != -1 && save->min == 1)
		len += ft_putcharl(sym);
	return (len);
}
