/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:15:37 by abdait-m          #+#    #+#             */
/*   Updated: 2021/05/18 01:47:27 by abdait-m         ###   ########.fr       */
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
		puts("hi");
    }
    else
    {
        curr->next = NULL;
        (*st) = curr;
		puts("hi3");
    }
}

// void    _pop_(t_stack *st, int num)
// {
//     printf("pop");
// }

int	_checker_(char *args, int index)
{
	if (((args[0] != '-' && args[0] != '+') && !ft_isdigit(args[index]))
			|| ((args[0] == '-' || args[0] == '+') && !ft_isdigit(args[1])))
		return (1);
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

void	_fill_stack_(t_ps *ps, char **args, int size)
{
	int	i;

	i = 1;
	ps->s_a = NULL;
	while (i < size)
	{
		_push_front_(&ps->s_a, ft_atoi(args[i]));
		printf("hid\n");
		i++;
	}
	while(ps->s_a)
	{
		// printf("hi");
		printf("%d ", ps->s_a->num);
		ps->s_a = ps->s_a->next;
	}
}

int main(int argc, char **argv)
{
    t_ps *ps;

    ps = malloc(sizeof(t_ps));
	if (_check_args_(argv, argc))
	{
		printf("Error\n");
		exit (0);
	}
	_fill_stack_(ps, argv, argc);
    free(ps);
    return (0);
}
