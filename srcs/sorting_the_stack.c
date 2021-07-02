/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_the_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:12:04 by abdait-m          #+#    #+#             */
/*   Updated: 2021/07/02 15:52:36 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	_sort_three_nums(t_ps *ps)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = ps->s_a;
	second = first->next;
	third = second->next;
	if (first->num > second->num && first->num < third->num)
		_sa_(ps, 1);
	else if (first->num > second->num && second->num > third->num)
	{
		_sa_(ps, 1);
		_rra_(ps, 1);
	}
	else if (third->num > second->num && first->num > third->num)
		_ra_(ps, 1);
	else if (first->num < second->num && first->num > third->num)
		_rra_(ps, 1);
	else if (third->num < second->num && third->num > first->num)
	{
		_sa_(ps, 1);
		_ra_(ps, 1);
	}
}

void	_sort_small_sizes_(t_ps *ps)
{
	int		num;

	ps->middle = ps->size_a / 2;
	while (1)
	{
		num = _get_smallest_num(ps);
		_which_instructions_(ps, num);
		if (_get_size_(&ps->s_a) == 3)
			break ;
	}
	_sort_three_nums(ps);
	while (_get_size_(&ps->s_b))
		_pa_(ps, 1);
}

void	_sort_last_chunk_(t_ps *ps)
{
	int		num;

	ps->middle = _get_size_(&ps->s_a) / 2;
	while (1)
	{
		num = _get_smallest_num(ps);
		_which_instructions_(ps, num);
		if (_get_size_(&ps->s_a) == 3)
			break ;
	}
	_sort_three_nums(ps);
	_last_step_(ps);
	while (_get_size_(&ps->s_b))
		_pa_(ps, 1);
}

void	_sort_large_sizes_(t_ps *ps, int nbr_ch)
{
	int	i;
	int	j;
	int	end;

	ps->chunk_s = ps->size_a / nbr_ch;
	end = ps->chunk_s;
	ps->middle = ps->size_a / 2;
	_sorting_the_array_(ps);
	i = 0;
	while (i < nbr_ch - 1)
	{
		j = 0;
		ps->pivot = ps->array[end];
		while (j < ps->chunk_s)
		{
			_look_for_num(ps);
			_which_instructions_(ps, ps->nbr);
			j++;
		}
		end += ps->chunk_s;
		i++;
	}
	_sort_last_chunk_(ps);
}

void	_sorting_the_stack_(t_ps *ps)
{
	if (ps->size_a == 2 && ps->s_a->num > ps->s_a->next->num)
		_sa_(ps, 1);
	else if (ps->size_a == 3)
		_sort_three_nums(ps);
	else if (ps->size_a > 3 && ps->size_a <= 10)
		_sort_small_sizes_(ps);
	else if (ps->size_a > 10 && ps->size_a <= 100)
		_sort_large_sizes_(ps, 5);
	else
		_sort_large_sizes_(ps, 12);
}
