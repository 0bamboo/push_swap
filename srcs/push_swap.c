/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:15:37 by abdait-m          #+#    #+#             */
/*   Updated: 2021/06/20 00:36:34 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/push_swap.h"



void	_fill_stack_(t_ps *ps, char **args, int size)
{
	int		i;
	long	tmp;
	int		j;

	i = 1;
	j = 0;
	ps->s_a = NULL;
	ps->s_b = NULL;
	ps->size_a = size;
	printf("size == |%d|", size);
	ps->array = malloc(sizeof(int) * ps->size_a);
	while (i < size)
	{
		tmp = _atoi_mod_(args[i]);
		if (tmp > MAX_INT || tmp < MIN_INT)
			_exit_error_();
		ps->array[j++] = tmp;
		_push_back_(&ps->s_a, tmp);
		i++;
	}
	if (_check_dup_(&ps->s_a, size))
		_exit_error_();
	_sorting_the_array_(ps)
}

void	_sorting_the_array_(t_ps *ps)
{
	if (ps->size_a <= 11)
		_insertion_sort_(ps);
	else if (ps->size_a > 11)
		_quick_sort_(ps->array, 0, ps->size_a - 1);
}

void	_sart_sorting_stack_(t_ps *ps)
{
	return ;
}

void	_the_start_(t_ps *ps)
{
	_fill_stack_(ps, argv, argc - 1);
	_start_sorting_stack_(ps);
}

int main(int argc, char **argv)
{
    t_ps *ps;

    ps = malloc(sizeof(t_ps));
	ps->err = 0;
	if (_check_args_(argv, argc))
		_exit_error_();
	_the_start_(ps);
    free(ps);
    return (0);
}
