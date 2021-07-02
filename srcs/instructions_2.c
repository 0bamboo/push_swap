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

void	_pa_(t_ps *ps, int print)
{
	_push_to_stack_(ps, 'a');
	if (print)
		puts("pa");
}

void	_pb_(t_ps *ps, int print)
{
	_push_to_stack_(ps, 'b');
	if (print)
		puts("pb");
}

void	_sa_(t_ps *ps, int print)
{
	_swap_(&ps->s_a);
	if (print)
		puts("sa");
}

void	_sb_(t_ps *ps, int print)
{
	_swap_(&ps->s_b);
	if (print)
		puts("sb");
}

void	_ss_(t_ps *ps, int print)
{
	_sa_(ps, 0);
	_sb_(ps, 0);
	if (print)
		puts("ss");
}
