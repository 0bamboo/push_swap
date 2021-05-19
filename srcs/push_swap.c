/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:15:37 by abdait-m          #+#    #+#             */
/*   Updated: 2021/05/19 01:59:58 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/push_swap.h"

void    _push_front_(t_stack **st, int num)
{
    t_stack *curr;

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

void	_swap_(t_stack **st, int size, char c)
{
	t_stack *curr;
	t_stack *tmp;
	int		t;

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

// void	_rotate_(t_stack **st, int size)
// {
	
// }

void    _pop_front_(t_stack **st)
{
	t_stack *pop;
	t_stack *ncurr;

	pop = (*st);
	if (!pop)
		return ;
	if (pop->next)
	{
		ncurr = pop->next;
		pop->next = NULL;
		ncurr->prev = NULL;
		(*st) = ncurr;
		free(pop);
		pop = NULL;
	}
	else
	{
		free((*st));
		(*st) = NULL;
	}
}

// void	_pop_back_(t_stack **st)
// {
	
// }
	
void	_push_to_stack_(t_ps *ps, char rule)
{
	int		tmp;

	if (ps->s_b && rule == 'a')
	{
		puts("pa");
		tmp = ps->s_b->num;
		_push_front_(&ps->s_a, tmp);
		_pop_front_(&ps->s_b);
	}
	else if (ps->s_a && rule == 'b')
	{
		puts("pb");
		tmp = ps->s_a->num;
		_push_front_(&ps->s_b, tmp);
		_pop_front_(&ps->s_a);
	}
}


int	_checker_(char *args, int index)
{
	if (((args[0] != '-' && args[0] != '+') && !ft_isdigit(args[index]))
			|| ((args[0] == '-' || args[0] == '+') && !ft_isdigit(args[1])))
		return (1);
	return (0);
}

int	_check_dup_(t_stack **s_a, int size)
{
	t_stack	*curr;
	t_stack	*check;
	int		tmp;
	int		i;

	curr = (*s_a);
	i = 0;
	if (curr)
	{
		while (i < size)
		{
			tmp = curr->num;
			check = curr->next;
			while (check)
			{
				if (tmp == check->num)
					return (1);
				check = check->next;
			}
			curr = curr->next;
			i++;
		}
	}
	return (0);
}

int   _check_args_(char **args, int size)
{
	int    i;
	int    j;

	i = 1;
	if (size < 2)
		return (1);
	while (i < size)
	{
		j = -1;
		while (args[i][++j])
		{
			if (_checker_(args[i], j))
				return (1);
		}
		i++;
	}
	return (0);
}

long	_atoi_mod_(const char *str)
{
	int		i;
	long	a;
	int		sign;

	a = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = (a * 10) + str[i] - 48;
		i++;
	}
	return (a * sign);
}

void    _empty_stack_(t_stack *st)
{
    t_stack *tmp;
    while (st)
    {
        tmp = st;
        st = st->next;
        free(tmp);
    }
}

void	_exit_error_(void)
{
	write(1, "Error\n", 6);
	exit (0);
}

void	_rotate_(t_ps *ps, char rule)
{
	int		tmp;
	
	if (rule == 'a' && ps->s_a)
	{
		tmp = ps->s_a->num;
		_pop_front_(&ps->s_a);
		_push_back_(&ps->s_a, tmp);
	}
	else if (rule == 'b' && ps->s_b)
	{
		tmp = ps->s_b->num;
		_pop_front_(&ps->s_b);
		_push_back_(&ps->s_b, tmp);
	}
}

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
	// _swap_(&ps->s_a, size - 1, 'a');
	// _push_to_stack_(ps, 'b');
	// _push_to_stack_(ps, 'b');
	// // _push_to_stack_(ps, 'a');
	// _push_to_stack_(ps, 'b');
	_rotate_(ps, 'a');
	_rotate_(ps, 'a');
	_rotate_(ps, 'a');
	_rotate_(ps, 'b');
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
