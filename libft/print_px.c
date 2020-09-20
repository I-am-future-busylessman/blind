/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_px.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 23:17:37 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/07/28 23:17:39 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_convert_16(size_t p, t_list *save)
{
	size_t	num;
	int		len;
	char	*tmp;
	char	*line;

	len = 1;
	num = p;
	while (num /= 16)
		len++;
	if ((line = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (line);
	if (save->type == 'X')
		tmp = ft_strdup("0123456789ABCDEF");
	else
		tmp = ft_strdup("0123456789abcdef");
	line[len] = '\0';
	while (len-- > 0)
	{
		line[len] = tmp[p % 16];
		p /= 16;
	}
	free(tmp);
	return (line);
}

static char		*ft_print_null_p(t_list *save)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	if (save->prc_num > 0 && save->prc == 1)
	{
		line = (char *)malloc(sizeof(char) * save->prc_num + 1);
		while (i != save->prc_num)
			line[i++] = '0';
		line[i] = '\0';
	}
	else if (save->prc == 0 || (save->prc == 1 && save->prc_num < 0))
		line = ft_strdup("0");
	else
		line = NULL;
	if (!line)
		line = ft_strdup("0x");
	else
	{
		tmp = line;
		line = ft_strjoin("0x", line);
		free(tmp);
	}
	return (line);
}

int				ft_print_p(t_list *save, va_list args)
{
	size_t	p;
	int		len;
	char	*line;
	char	*tmp;

	p = (long long)va_arg(args, void *);
	if (!p)
		line = ft_print_null_p(save);
	else
	{
		line = ft_convert_16(p, save);
		if (save->prc_num > (int)ft_strlen(line))
			line = ft_treat_prc(line, save);
		tmp = line;
		line = ft_strjoin("0x", line);
		free(tmp);
	}
	if (save->wd > (int)ft_strlen(line))
		len = ft_treat_wd(line, ft_strlen(line), save);
	else
		len = ft_putstrl(line);
	free(line);
	return (len);
}

int				ft_print_x(t_list *save, va_list args)
{
	size_t	x;
	int		len;
	char	*line;

	len = 0;
	x = va_arg(args, unsigned int);
	line = ft_convert_16(x, save);
	len = ft_strlen(line);
	if ((len < save->prc_num && save->prc == 1)
	|| (len < save->wd && save->zero == 1))
		line = ft_treat_prc(line, save);
	len = ft_strlen(line);
	if (x == 0 && save->prc_num == 0 && save->prc == 1)
		len = ft_treat_wd(NULL, 0, save);
	else if (save->wd > len)
		len = ft_treat_wd(line, len, save);
	else
		len = ft_putstrl(line);
	free(line);
	return (len);
}
