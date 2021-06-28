/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:31:45 by abdait-m          #+#    #+#             */
/*   Updated: 2021/06/28 11:32:04 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	_which_instructions_(t_ps *ps, int num)
{
	while (1)
	{
		ps->top = _get_first_element(&ps->s_a);
		if (num == ps->top)
		{
			_pb_(ps);
			break;
		}
		else if (ps->idx <= ps->middle)
			_ra_(ps);
		else if (ps->idx > ps->middle)
			_rra_(ps);
	}
}

int 	_is_the_smallest_(t_stack **st, int small)
{
	t_stack *curr;

	curr = (*st);
	while (curr)
	{
		if (curr->num < small)
			return 0;
		curr = curr->next;
	}
	return 1;
}

void	_look_for_num(t_ps *ps)
{
	t_stack *curr;
	int		i;

	curr = ps->s_a;
	i = 0;
	while (curr)
	{
		if (curr->num < ps->pivot/*&& _is_the_smallest_(&ps->s_a, curr->num)*/)
		{
			ps->idx = i;
			ps->nbr = curr->num;
			break;
		}
		i++;
		curr = curr->next;
	}
}