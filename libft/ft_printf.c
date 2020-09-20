/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:20:08 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/07/28 22:20:13 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_treat_save(char *line, int i, t_list *save, va_list args)
{
	i++;
	while (line[i] == '0' || line[i] == '-')
	{
		save = ft_save_flags(line, i, save);
		i++;
	}
	while (ft_isdigit(line[i]) || line[i] == '*')
	{
		if (save->wd == 0)
			save = ft_save_wd(line, i, save, args);
		i++;
	}
	if (line[i] == '.')
	{
		save->prc = 1;
		i++;
		if (line[i] == '.')
			return (i);
		save = ft_save_prc(line, i, save, args);
		while (ft_isdigit(line[i]) || line[i] == '*')
			i++;
	}
	save->type = line[i];
	return (i);
}

int		ft_print_save(t_list *save, va_list args)
{
	int s;

	if (save->type != '%' && save->prc == 1 && save->prc_num >= 0)
		save->zero = 0;
	if (save->type == 'c')
		s = ft_print_c(save, args);
	else if (save->type == 's')
		s = ft_print_s(save, args);
	else if (save->type == 'p')
		s = ft_print_p(save, args);
	else if (save->type == 'i' || save->type == 'd')
		s = ft_print_di(save, args);
	else if (save->type == 'u')
		s = ft_print_u(save, args);
	else if (save->type == 'x' || save->type == 'X')
		s = ft_print_x(save, args);
	else if (save->type == '%')
		s = ft_print_per(save);
	else
		return (0);
	return (s);
}

int		ft_print_line(char *line, va_list args, int count)
{
	t_list	save;
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '%' && line[i + 1])
		{
			save = ft_init_save();
			i = ft_treat_save(line, i, &save, args);
			if (ft_is_type(line[i]) == 0)
				count += ft_print_save(&save, args);
			else
				count += ft_putcharl(line[i]);
		}
		else if (line[i] != '%')
			count += ft_putcharl(line[i]);
		i++;
	}
	return (count);
}

int		ft_printf(const char *input, ...)
{
	va_list	args;
	int		count;
	char	*line;

	line = ft_strdup(input);
	va_start(args, input);
	count = 0;
	count = ft_print_line(line, args, count);
	va_end(args);
	free(line);
	return (count);
}
