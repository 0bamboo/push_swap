/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 15:49:10 by abdait-m          #+#    #+#             */
/*   Updated: 2021/07/01 12:51:29 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_cleanall(char **s_tab)
{
	if (s_tab && *s_tab)
	{
		free(*s_tab);
		*s_tab = NULL;
	}
}

int	ft_checkline(char **s_tab, char **line, int byt)
{
	int			i;
	char		*tmp2;

	i = 0;
	while (s_tab[0][i] != '\n' && s_tab[0][i] != '\0')
		i++;
	if (s_tab[0][i] == '\n')
	{
		free(*line);
		*line = ft_substr(*s_tab, 0, i);
		tmp2 = ft_strdup(*s_tab + i + 1);
		free(*s_tab);
		*s_tab = tmp2;
		if (s_tab[0][0] == '\0')
			ft_cleanall(s_tab);
	}
	else
	{
		free(*line);
		*line = ft_strdup(s_tab[0]);
		ft_cleanall(s_tab);
		if (!byt)
			return (0);
	}
	return (1);
}

int	ft_help(char **line, char **s_tab, int byt)
{
	if (line)
		*line = ft_strdup("");
	if (byt == -1)
		return (-1);
	else if (byt == 0 && !*s_tab)
		return (0);
	else
		return (ft_checkline(s_tab, line, byt));
}

char	*_append_to_line_(char *s_tab, char *buff)
{
	char	*tmp;

	tmp = s_tab;
	s_tab = ft_strjoin(tmp, buff);
	free(tmp);
	return (s_tab);
}

int	get_next_line(int fd, char **line)
{
	static char		*s_tab;
	char			*buff;
	int				byt;
	int				b_size;

	b_size = 1;
	buff = (char *)malloc(b_size + 1);
	if (fd < 0 || b_size <= 0
		|| !line || !buff)
		return (ft_help(line, &s_tab, -1));
	while ((byt = read(fd, buff, b_size)) > 0)
	{
		buff[byt] = '\0';
		if (s_tab == NULL)
			s_tab = ft_strdup(buff);
		else
			s_tab = _append_to_line_(s_tab, buff);
		if (ft_strchr(s_tab, '\n'))
			break ;
	}
	free(buff);
	return (ft_help(line, &s_tab, byt));
}
