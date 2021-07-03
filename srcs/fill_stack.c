/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:50:03 by abdait-m          #+#    #+#             */
/*   Updated: 2021/07/03 09:32:10 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	_fill_stack_(t_ps *ps)
{
	int		i;
	long	tmp;

	i = 0;
	ps->size_a = ps->fsize - 1;
	ps->array = malloc(sizeof(int) * ps->size_a);
	if (!ps->array)
		_exit_error_(ps);
	while (i < ps->size_a)
	{
		tmp = _atoi_mod_(ps->argv[i]);
		if (tmp > MAX_INT || tmp < MIN_INT)
			_exit_error_(ps);
		ps->array[i++] = tmp;
		_push_back_(&ps->s_a, tmp);
	}
	if (_check_dup_(&ps->s_a))
		_exit_error_(ps);
}

int	_get_first_element(t_stack **st)
{
	return ((*st)->num);
}

void	_the_start_(t_ps *ps)
{
	_fill_stack_(ps);
	if (!_already_sorted(ps))
		_sorting_the_stack_(ps);
}

void	_init_vars_(t_ps *ps)
{
	ps->array = NULL;
	ps->argv = NULL;
	ps->s_a = NULL;
	ps->s_b = NULL;
	ps->tmp = NULL;
	ps->input = NULL;
	ps->sorted = 1;
}
