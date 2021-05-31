/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:15:37 by abdait-m          #+#    #+#             */
/*   Updated: 2021/05/31 15:02:10 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/push_swap.h"

void	_fill_stack_(t_ps *ps, char **args, int size)
{
	int	i;
	long	tmp;

	i = 1;
	ps->s_a = NULL;
	ps->s_b = NULL;
	while (i < size)
	{
		tmp = _atoi_mod_(args[i]);
		if (tmp > MAX_INT || tmp < MIN_INT)
			_exit_error_();
		_push_back_(&ps->s_a, tmp);
		i++;
	}
	if (_check_dup_(&ps->s_a, size - 1))
		_exit_error_();
	_sa_(ps);
	_pb_(ps);
	_pb_(ps);
	_pb_(ps);
	puts("-------------stack a : -----------------");
	printf("top ");
	while(ps->s_a)
	{
		printf("-> %d ", ps->s_a->num);
		ps->s_a = ps->s_a->next; 
	}
	puts("");
	puts("--------------stack b : ------------------");
	printf("top ");
	while(ps->s_b)
	{
		printf("-> %d ", ps->s_b->num);
		ps->s_b = ps->s_b->next;
	}
	puts("");
}

void	_ra_(t_ps *ps)
{
	_rotate_(ps, 'a');
}

void	_rb_(t_ps *ps)
{
	_rotate_(ps, 'b');
}

void	_rr_(t_ps *ps)
{
	_ra_(ps);
	_rb_(ps);
}

void	_rra_(t_ps *ps)
{
	_reverse_rotate_(ps, 'a');
}

void	_rrb_(t_ps *ps)
{
	_reverse_rotate_(ps, 'b');
}

void	_rrr_(t_ps *ps)
{
	_rra_(ps);
	_rrb_(ps);
}

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

int main(int argc, char **argv)
{
    t_ps *ps;

    ps = malloc(sizeof(t_ps));
	ps->err = 0;
	if (_check_args_(argv, argc))
		_exit_error_();
	_fill_stack_(ps, argv, argc);
    free(ps);
    return (0);
}
