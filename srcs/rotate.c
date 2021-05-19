/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:44:29 by abdait-m          #+#    #+#             */
/*   Updated: 2021/05/19 15:08:30 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int		_get_last_element_(t_stack **st)
{
	t_stack		*curr;

	curr = (*st);
	if (curr)
		while (curr->next)
			curr = curr->next;
	return (curr->num);
}

int	_get_size_(t_stack **st)
{
	int	size;
	t_stack	*curr;

	size = 0;
	curr = (*st);
	if (curr)
		while (curr)
		{
			curr = curr->next;
			size++;
		}
	return (size);
}

void	_swap_(t_stack **st, char c)
{
	t_stack *curr;
	t_stack *tmp;
	int		t;
	int		size;

	size = _get_size_(st);
	if (size < 2)
		return ;
	curr = (*st);
	tmp = curr->next;
	t = tmp->num;
	tmp->num = curr->num;
	curr->num = t;
	if (c == 'a')
		puts("sa");
	else
		puts("sb");
}

void	_reverse_rotate_(t_ps *ps, char rule)
{
	int	tmp;

	if (rule == 'a' && ps->s_a)
	{
		if (_get_size_(&ps->s_a) < 2)
			return ;
		tmp = _get_last_element_(&ps->s_a);
		_pop_back_(&ps->s_a);
		_push_front_(&ps->s_a, tmp);
	}
	else if (rule == 'b' && ps->s_b)
	{
		if (_get_size_(&ps->s_b) < 2)
			return ;
		tmp = _get_last_element_(&ps->s_b);
		_pop_back_(&ps->s_b);
		_push_front_(&ps->s_b, tmp);
	}
}

void	_rotate_(t_ps *ps, char rule)
{
	int		tmp;
	
	if (rule == 'a' && ps->s_a)
	{
		if (_get_size_(&ps->s_a) < 2)
			return ;
		tmp = ps->s_a->num;
		_pop_front_(&ps->s_a);
		_push_back_(&ps->s_a, tmp);
	}
	else if (rule == 'b' && ps->s_b)
	{
		if (_get_size_(&ps->s_b) < 2)
			return ;
		tmp = ps->s_b->num;
		_pop_front_(&ps->s_b);
		_push_back_(&ps->s_b, tmp);
	}
}