/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:42:00 by abdait-m          #+#    #+#             */
/*   Updated: 2021/07/01 12:44:09 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	_is_sorted_(t_ps *ps)
{
	t_stack	*curr;
	t_stack	*ncurr;

	curr = ps->s_a;
	while (curr)
	{
		ncurr = curr->next;
		while (ncurr)
		{
			if (curr->num > ncurr->num)
			{
				ps->sorted = 0;
				return ;
			}
			ncurr = ncurr->next;
		}
		curr = curr->next;
	}
}

void	_check_if_stack_sorted_(t_ps *ps)
{
	if (_get_size_(&ps->s_b) || !_get_size_(&ps->s_a))
		ps->sorted = 0;
	else
		_is_sorted_(ps);
	if (ps->sorted)
		puts("OK");
	else
		puts("KO");
}

int	_check_line_(t_ps *ps)
{
	if (!ft_strncmp(ps->input, "pa", 3))
		_pa_(ps, 0);
	else if (!ft_strncmp(ps->input, "pb", 3))
		_pb_(ps, 0);
	else if (!ft_strncmp(ps->input, "sb", 3))
		_sb_(ps, 0);
	else if (!ft_strncmp(ps->input, "sa", 3))
		_sa_(ps, 0);
	else if (!ft_strncmp(ps->input, "ra", 3))
		_ra_(ps, 0);
	else if (!ft_strncmp(ps->input, "rb", 3))
		_rb_(ps, 0);
	else if (!ft_strncmp(ps->input, "rra", 3))
		_rra_(ps, 0);
	else if (!ft_strncmp(ps->input, "rrb", 3))
		_rrb_(ps, 0);
	else if (!ft_strncmp(ps->input, "rr", 3))
		_rr_(ps, 0);
	else if (!ft_strncmp(ps->input, "rrr", 3))
		_rrr_(ps, 0);
	else if (!ft_strncmp(ps->input, "ss", 3))
		_ss_(ps, 0);
	else
		return (1);
	return (0);
}
