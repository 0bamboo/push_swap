/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:12:35 by abdait-m          #+#    #+#             */
/*   Updated: 2021/06/28 16:02:47 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int		_get_args_size(t_ps *ps, char **args, int argc)
{
	int size;

	if (argc < 2)
		return (1);
	ps->i = 1;
	size = 0;
	ps->argv = NULL;
	ps->s_a = NULL;
	while (ps->i < argc)
	{
		ps->j = -1;
		ps->tmp = _split_all(args[ps->i]);
		if (!ps->tmp[0])
			return (1);
		puts("hi");
		while (ps->tmp[++ps->j])
		{
			if (_check_args_(ps->tmp[ps->j]))
			{
				free(ps->tmp[ps->j]);
				free(ps->tmp);
				puts("hello");
				return (1);
			}
			free(ps->tmp[ps->j]);
		}
		free(ps->tmp);
		size += ps->j;
		++ps->i;
	}
	ps->fsize = size + 1;
	return (0);
}

int	_get_args_(t_ps *ps, char **args, int argc)
{
	ps->i = 1;
	ps->idx = 0;
	if (!(ps->argv = (char **)malloc(sizeof(char *) * ps->fsize)))
		return (1);
	while (ps->i < argc)
	{
		ps->j = 0;
		ps->tmp = _split_all(args[ps->i]);
		puts("hello");
		while (ps->tmp[ps->j])
		{
			ps->argv[ps->idx++] = ft_strdup(ps->tmp[ps->j++]);
			free(ps->tmp[ps->j]);
		}
		free(ps->tmp);
		++ps->i;
	}
	ps->argv[ps->idx] = NULL;
	return (0);
}