/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:15:37 by abdait-m          #+#    #+#             */
/*   Updated: 2021/06/20 20:30:33 by abdait-m         ###   ########.fr       */
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
	printf("size == |%d|\n", size);
	ps->array = malloc(sizeof(int) * ps->size_a);
	while (i < size + 1)
	{
		tmp = _atoi_mod_(args[i]);
		printf("tmp = %li \n", tmp);
		if (tmp > MAX_INT || tmp < MIN_INT)
			_exit_error_();
		ps->array[j++] = tmp;
		_push_back_(&ps->s_a, tmp);
		i++;
	}
	if (_check_dup_(&ps->s_a))
		_exit_error_();
	i = -1;
	while (++i < ps->size_a)
		printf("|%d| ", ps->array[i]);
	puts("");
	_sorting_the_array_(ps);
}

void	_sorting_the_array_(t_ps *ps)
{
	if (ps->size_a <= 11)
		_insertion_sort_(ps);
	else if (ps->size_a > 11)
		_quick_sort_(ps->array, 0, ps->size_a - 1);
}

void	_start_sorting_stack_(t_ps *ps)
{
	if (ps->size_a == 3)
	return ;
}

void	_the_start_(t_ps *ps, int argc, char **argv)
{
	int i;

	i = -1;
	_fill_stack_(ps, argv, argc - 1);
	while (++i < ps->size_a)
		printf("|%d| ", ps->array[i]);
	puts("");
	// _start_sorting_stack_(ps);
}

int main(int argc, char **argv)
{
    t_ps *ps;
	// int i = -1;

    ps = malloc(sizeof(t_ps));
	ps->err = 0;
	// while (argv[++i])
	// 	printf("|%s| ", argv[i]);
	// puts("");
	if (_check_args_(argv, argc))
		_exit_error_();
	_the_start_(ps, argc, argv);
    free(ps);
    return (0);
}
