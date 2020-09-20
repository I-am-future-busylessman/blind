/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:22:23 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/07/28 22:22:24 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_treat_sign(char *line, int sign)
{
	char *tmp;

	if (sign == 1)
	{
		tmp = line;
		line = ft_strjoin("-", line);
		free(tmp);
	}
	return (line);
}

static int	ft_print_di_2(t_list *save, char *line, int i)
{
	int		len;

	len = 0;
	if ((((int)ft_strlen(line) < save->prc_num) && save->prc == 1) ||
	(((int)ft_strlen(line) + save->sign) < save->wd && save->zero == 1))
		line = ft_treat_prc(line, save);
	line = ft_treat_sign(line, save->sign);
	if (i == 0 && save->prc_num == 0 && save->prc == 1)
		len = ft_treat_wd(NULL, 0, save);
	else if (save->wd > (int)ft_strlen(line) && save->zero == 0)
		len = ft_treat_wd(line, ft_strlen(line), save);
	else
		len = ft_putstrl(line);
	free(line);
	return (len);
}

int			ft_print_di(t_list *save, va_list args)
{
	int		len;
	int		i;
	char	*tmp;
	char	*line;

	i = va_arg(args, int);
	if (i == -2147483648)
		line = ft_strdup("-2147483648");
	else
		line = ft_itoa(i);
	if (ft_strrchr(line, '-'))
	{
		save->sign = 1;
		tmp = line;
		line = ft_substr(line, 1, ft_strlen(line));
		free(tmp);
	}
	len = ft_print_di_2(save, line, i);
	return (len);
}

int			ft_print_u(t_list *save, va_list args)
{
	unsigned int	u;
	int				len;
	char			*line;

	u = (unsigned int)va_arg(args, unsigned int);
	line = ft_utoa(u);
	len = ft_strlen(line);
	if ((len < save->prc_num && save->prc == 1) ||
	(len < save->wd && save->zero == 1))
		line = ft_treat_prc(line, save);
	len = ft_strlen(line);
	if (u == 0 && save->prc_num == 0 && save->prc == 1)
		len = ft_treat_wd(NULL, 0, save);
	else if (save->wd > len && save->zero == 0)
		len = ft_treat_wd(line, len, save);
	else
		len = ft_putstrl(line);
	free(line);
	return (len);
}
