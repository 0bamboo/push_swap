/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:31:45 by abdait-m          #+#    #+#             */
/*   Updated: 2021/07/02 11:30:30 by abdait-m         ###   ########.fr       */
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
			_pb_(ps, 1);
			break ;
		}
		else if (ps->idx <= ps->middle)
			_ra_(ps, 1);
		else if (ps->idx > ps->middle)
			_rra_(ps, 1);
	}
}

void	_look_for_num(t_ps *ps)
{
	t_stack	*curr;
	int		i;

	curr = ps->s_a;
	i = 0;
	while (curr)
	{
		if (curr->num < ps->pivot)
		{
			ps->idx = i;
			ps->nbr = curr->num;
			break ;
		}
		i++;
		curr = curr->next;
	}
}
