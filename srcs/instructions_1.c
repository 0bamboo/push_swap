/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 23:45:28 by abdait-m          #+#    #+#             */
/*   Updated: 2021/06/19 23:45:28 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	_ra_(t_ps *ps)
{
	_rotate_(ps, 'a');
	puts("ra");
}

void	_rb_(t_ps *ps)
{
	_rotate_(ps, 'b');
	puts("rb");
}

void	_rr_(t_ps *ps)
{
	_ra_(ps);
	_rb_(ps);
	puts("rr");
}

void	_rra_(t_ps *ps)
{
	_reverse_rotate_(ps, 'a');
	puts("rra");
}

void	_rrb_(t_ps *ps)
{
	_reverse_rotate_(ps, 'b');
	puts("rrb");
}