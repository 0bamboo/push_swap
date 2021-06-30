/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:52:42 by abdait-m          #+#    #+#             */
/*   Updated: 2021/06/30 19:40:28 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

long	_atoi_mod_(const char *str)
{
	int		i;
	long	a;
	int		sign;

	a = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = (a * 10) + str[i] - 48;
		i++;
	}
	return (a * sign);
}

void    _empty_stack_(t_stack *st)
{
    t_stack *tmp;
    while (st)
    {
        tmp = st;
        st = st->next;
        free(tmp);
    }
}



void	_clear_all_(t_ps *ps)
{
	int	i;

	i = -1;
	if (ps->s_a)
		_empty_stack_(ps->s_a);
	if (ps->s_b)
		_empty_stack_(ps->s_b);
	if (ps->array)
		free(ps->array);
	if (ps->tmp)
	{
		while (ps->tmp[ps->j])
			free(ps->tmp[ps->j++]);
		free(ps->tmp);
	}
	i = -1;
	if (ps->argv)
	{
		while (ps->argv[++i])
			free(ps->argv[i]);
		free(ps->argv);
	}
	if (ps->input)
		free(ps->input);
	free(ps);
}

void	_exit_error_(t_ps *ps)
{
	_clear_all_(ps);
	write(1, "Error\n", 6);
	exit (0);
}
