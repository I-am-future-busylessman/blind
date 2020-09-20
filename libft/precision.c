/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:21:38 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/07/28 22:21:52 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_treat_prc(char *line, t_list *save)
{
	int		len;
	int		i;
	char	*zeros;
	char	*tmp;

	len = ft_strlen(line);
	if (len < save->prc_num)
		i = save->prc_num;
	if (len < save->wd && save->zero == 1)
		i = save->wd - save->sign;
	len = i - len;
	if (!(zeros = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		zeros[i] = '0';
		i++;
	}
	zeros[i] = '\0';
	tmp = line;
	line = ft_strjoin(zeros, line);
	free(tmp);
	free(zeros);
	return (line);
}
