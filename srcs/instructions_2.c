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
	puts("pa");
}

void	_pb_(t_ps *ps)
{
	_push_to_stack_(ps, 'b');
	puts("pb");
}



void	_sa_(t_ps *ps)
{
	_swap_(&ps->s_a);
	puts("sa");
}


void	_sb_(t_ps *ps)
{
	_swap_(&ps->s_b);
	puts("sb");
}

void	_ss_(t_ps *ps)
{
	_sa_(ps);
	_sb_(ps);
	puts("ss");
}

void	_rrr_(t_ps *ps)
{
	_rra_(ps);
	_rrb_(ps);
	puts("rrr");
}