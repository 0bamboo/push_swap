/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 23:45:22 by abdait-m          #+#    #+#             */
/*   Updated: 2021/06/19 23:45:22 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	_pa_(t_ps *ps)
{
	_push_to_stack_(ps, 'a');
}

void	_pb_(t_ps *ps)
{
	_push_to_stack_(ps, 'b');
}



void	_sa_(t_ps *ps)
{
	_swap_(&ps->s_a);
}


void	_sb_(t_ps *ps)
{
	_swap_(&ps->s_b);
}

void	_ss_(t_ps *ps)
{
	_sa_(ps);
	_sb_(ps);
}

void	_rrr_(t_ps *ps)
{
	_rra_(ps);
	_rrb_(ps);
}