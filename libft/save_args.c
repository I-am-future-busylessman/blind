/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:22:57 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/07/28 22:23:38 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_save_flags(char *line, int i, t_list *save)
{
	if (line[i] == '0')
		save->zero = 1;
	else if (line[i] == '-')
		save->min = 1;
	if (save->zero == 1 && save->min == 1)
		save->zero = 0;
	return (save);
}

t_list	*ft_save_wd(char *line, int i, t_list *save, va_list args)
{
	if (line[i] == '*')
		save->wd = va_arg(args, int);
	else if (ft_isdigit(line[i]))
		save->wd = ft_atoi(&(line[i]));
	if (save->wd < 0)
	{
		save->wd *= -1;
		save->min = 1;
		save->zero = 0;
	}
	return (save);
}

t_list	*ft_save_prc(char *line, int i, t_list *save, va_list args)
{
	if (line[i] == '*')
		save->prc_num = va_arg(args, int);
	else if (ft_isdigit(line[i]))
		save->prc_num = ft_atoi(&(line[i]));
	return (save);
}
