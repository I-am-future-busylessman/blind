/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:22:06 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/07/28 22:22:08 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_treat_wd_c(t_list *save, char c)
{
	int len;
	int sym;

	len = 0;
	if (save->zero == 1 && save->type == '%')
		sym = '0';
	else
		sym = ' ';
	while (save->wd-- != 1 && save->min == 0)
		len += ft_putcharl(sym);
	len += ft_putcharl(c);
	while (save->wd-- != 0 && save->min == 1)
		len += ft_putcharl(sym);
	return (len);
}

int			ft_print_c(t_list *save, va_list args)
{
	int		len;
	char	c;

	len = 0;
	c = va_arg(args, int);
	if (save->wd > 1)
		len = ft_treat_wd_c(save, c);
	else
		len = ft_putcharl(c);
	return (len);
}

static int	ft_print_null_s(t_list *save)
{
	int len;

	len = 0;
	if (save->wd > 0)
		len = ft_treat_wd(NULL, 0, save);
	return (len);
}

int			ft_print_s(t_list *save, va_list args)
{
	char	*s;
	char	*line;
	int		len;

	s = va_arg(args, char*);
	if (save->prc_num == 0 && save->prc == 1)
		return (ft_print_null_s(save));
	if (!s)
		s = ft_strdup("(null)");
	else
		s = ft_strdup(s);
	len = ft_strlen(s);
	if ((save->prc_num >= 0 && save->prc == 1))
		len = (len < save->prc_num ? len : save->prc_num);
	else
		len = ft_strlen(s);
	line = (char *)malloc(sizeof(char) * (len + 1));
	ft_strlcpy(line, s, (len + 1));
	if (save->wd > len)
		len = ft_treat_wd(line, len, save);
	else
		len = ft_putstrl(line);
	free(line);
	free(s);
	return (len);
}

int			ft_print_per(t_list *save)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	if (save->wd > 1 && save->zero == 1)
	{
		i = 0;
		line = (char *)malloc(sizeof(char) * (save->wd + 1));
		while (save->wd-- != 1)
			line[i++] = '0';
		line[i++] = '%';
		line[i++] = '\0';
		len = ft_putstrl(line);
		free(line);
	}
	else if (save->wd > 1)
		len = ft_treat_wd_c(save, '%');
	else
		len = ft_putcharl('%');
	return (len);
}
