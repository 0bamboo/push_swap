/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:43:46 by abdait-m          #+#    #+#             */
/*   Updated: 2021/07/02 11:13:54 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	_pop_front_(t_stack **st)
{
	t_stack	*pop;
	t_stack	*curr;

	pop = (*st);
	if (!pop)
		return ;
	if (pop->next)
	{
		curr = pop->next;
		pop->next = NULL;
		curr->prev = NULL;
		(*st) = curr;
		free(pop);
		pop = NULL;
	}
	else
	{
		free((*st));
		(*st) = NULL;
	}
}

void	_pop_back_(t_stack **st)
{
	t_stack	*curr;

	curr = (*st);
	if (curr)
		while (curr->next)
			curr = curr->next;
	curr->prev->next = NULL;
	free(curr);
	curr = NULL;
}

void	_push_front_(t_stack **st, int num)
{
	t_stack	*curr;

	curr = malloc(sizeof(t_stack));
	curr->prev = NULL;
	curr->num = num;
	if ((*st))
	{
		curr->next = (*st);
		(*st)->prev = curr;
		(*st) = curr;
	}
	else
	{
		curr->next = NULL;
		(*st) = curr;
	}
}

void	_push_back_(t_stack **st, int num)
{
	t_stack	*curr;
	t_stack	*head;

	head = (*st);
	curr = malloc(sizeof(t_stack));
	curr->prev = NULL;
	curr->num = num;
	curr->next = NULL;
	if (!head)
		(*st) = curr;
	else
	{
		while (head->next)
			head = head->next;
		head->next = curr;
		curr->prev = head;
	}
}

void	_push_to_stack_(t_ps *ps, char rule)
{
	int	tmp;

	if (ps->s_b && rule == 'a')
	{
		tmp = ps->s_b->num;
		_pop_front_(&ps->s_b);
		_push_front_(&ps->s_a, tmp);
	}
	else if (ps->s_a && rule == 'b')
	{
		tmp = ps->s_a->num;
		_pop_front_(&ps->s_a);
		_push_front_(&ps->s_b, tmp);
	}
}
