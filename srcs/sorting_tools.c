/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:17:25 by abdait-m          #+#    #+#             */
/*   Updated: 2021/07/02 15:59:08 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	_rrr_(t_ps *ps, int print)
{
	_rra_(ps, 0);
	_rrb_(ps, 0);
	if (print)
		puts("rrr");
}

int	_already_sorted(t_ps *ps)
{
	int	i;
	int	j;
	int	check;

	i = -1;
	while (++i < ps->size_a)
	{
		check = ps->array[i];
		j = i + 1;
		while (j < ps->size_a)
		{
			if (check > ps->array[j])
				return (0);
			j++;
		}
	}
	return (1);
}

int	_get_smallest_num(t_ps *ps)
{
	t_stack	*curr;
	int		small;
	int		i;

	curr = ps->s_a;
	small = MAX_INT;
	i = 0;
	while (curr)
	{
		if (curr->num < small)
		{
			ps->idx = i;
			small = curr->num;
		}
		curr = curr->next;
		i++;
	}
	return (small);
}

int	_get_largest_num(t_ps *ps)
{
	t_stack	*curr;
	int		large;
	int		i;

	curr = ps->s_b;
	large = MIN_INT;
	i = 0;
	while (curr)
	{
		if (curr->num > large)
		{
			ps->idx = i;
			large = curr->num;
		}
		curr = curr->next;
		i++;
	}
	return (large);
}

void	_last_step_(t_ps *ps)
{
	int	num;

	ps->middle = _get_size_(&ps->s_b) / 2;
	while (1)
	{
		num = _get_largest_num(ps);
		while (1)
		{
			ps->top = _get_first_element(&ps->s_b);
			if (num == ps->top)
			{
				_pa_(ps, 1);
				ps->middle = _get_size_(&ps->s_b) / 2;
				break ;
			}
			else if (ps->idx <= ps->middle)
				_rb_(ps, 1);
			else if (ps->idx > ps->middle)
				_rrb_(ps, 1);
		}
		if (_get_size_(&ps->s_b) == 0)
			break ;
	}
}
