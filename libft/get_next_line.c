/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 00:00:14 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/07/31 00:00:19 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_new_keep(char **keep, char *str, int start)
{
	char	*temp;

	temp = *keep;
	if (!(*keep = ft_substr(str, start, ft_strlen(str) - start)))
	{
		free(temp);
		return (-1);
	}
	free(temp);
	return (0);
}

int	ft_follow_str(char *str, char *sym)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	*sym = str[i];
	return (i);
}

int	ft_write_line(char *buf, char **line, char **keep)
{
	char	*str;
	char	*temp;
	char	sym;
	int		i;

	i = ft_follow_str(buf, &sym);
	if (!(str = ft_substr(buf, 0, i)))
		return (-1);
	temp = *line;
	if (!(*line = ft_strjoin(*line, str)))
	{
		free(temp);
		free(str);
		return (-1);
	}
	free(temp);
	free(str);
	if (buf[i] != '\0')
		if (ft_new_keep(keep, buf, i + 1) == -1)
			return (-1);
	if (buf[i] == '\n')
		return (1);
	return (2);
}

int	ft_re_keep(char **keep, char **line)
{
	char	*temp;
	char	sym;

	temp = *line;
	if (!(*line = ft_substr(*keep, 0, ft_follow_str(*keep, &sym))))
	{
		free(temp);
		return (-1);
	}
	free(temp);
	if (ft_follow_str(*keep, &sym) != (int)ft_strlen(*keep))
	{
		if (ft_new_keep(keep, *keep, ft_follow_str(*keep, &sym) + 1) == -1)
			return (-1);
		if (sym == '\n')
			return (1);
	}
	else
	{
		free(*keep);
		*keep = NULL;
	}
	return (2);
}

int	get_next_line(int fd, char **line)
{
	static char	*keep;
	char		*buf;
	int			res;

	if (read(fd, NULL, 0) == -1 || !(*line = ft_strdup("")))
		return (-1);
	if (keep)
	{
		res = ft_re_keep(&keep, line);
		if (res != 2)
			return (res);
	}
	if (!(buf = (char*)malloc((64 + 1) * sizeof(char))))
		return (-1);
	while ((res = read(fd, buf, 64)) > 0)
	{
		buf[res] = '\0';
		if ((res = ft_write_line(buf, line, &keep)) != 2)
		{
			free(buf);
			return (res);
		}
	}
	free(buf);
	return (0);
}
