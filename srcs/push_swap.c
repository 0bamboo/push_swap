/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:15:37 by abdait-m          #+#    #+#             */
/*   Updated: 2021/06/26 17:48:03 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../header/push_swap.h"



void	_fill_stack_(t_ps *ps)
{
	int		i;
	long	tmp;
	int		j;

	i = 0;
	j = 0;
	ps->s_a = NULL;
	ps->s_b = NULL;
	ps->size_a = ps->fsize - 1;
	ps->array = malloc(sizeof(int) * ps->size_a);
	while (i < ps->size_a)
	{
		tmp = _atoi_mod_(ps->argv[i]);
		if (tmp > MAX_INT || tmp < MIN_INT)
			_exit_error_();
		ps->array[i++] = tmp;
		_push_back_(&ps->s_a, tmp);
	}
	if (_check_dup_(&ps->s_a))
		_exit_error_();
	printf("sorted or not : |%d|\n", _already_sorted(ps));
	// _sorting_the_array_(ps);
}

void	_sorting_the_array_(t_ps *ps)
{
	if (ps->size_a <= 11)
		_insertion_sort_(ps);
	else if (ps->size_a > 11)
		_quick_sort_(ps->array, 0, ps->size_a - 1);
}

void	_sort_three_nums(t_ps *ps)
{
	t_stack *first;
	t_stack *second;
	t_stack *third;
	
	first = ps->s_a;
	second = first->next;
	third = second->next;
	if (first->num > second->num && first->num < third->num)
		_sa_(ps);
	else if (first->num > second->num && second->num > third->num)
	{
		_sa_(ps);
		_rra_(ps);
	}
	else if (third->num > second->num && first->num > third->num)
		_ra_(ps);
	else if (first->num < second->num && first->num > third->num)
		_rra_(ps);
	else if (third->num < second->num && third->num > first->num)
	{
		_sa_(ps);
		_ra_(ps);
	}
}

int		_already_sorted(t_ps *ps)
{
	int		i;
	int		j;
	int		check;
	
	i = -1;
	while (++i < ps->size_a)
	{
		check = ps->array[i];
		j = i + 1;
		while (j < ps->size_a)
		{
			if (check > ps->array[j])
				return (0);
			j++;
		}
	}
	return (1);
}

int		_get_smallest_num(t_ps *ps)
{
	t_stack *curr;
	int		small;
	int		i;

	curr = ps->s_a;
	small = MAX_INT;
	i = 0;
	while (curr)
	{
		if (curr->num < small)
		{
			ps->idx = i;
			small = curr->num;
		}
		curr = curr->next;
		i++;
	}
	return (small);
}

int		_get_first_element(t_stack **st)
{
	return ((*st)->num);
}

void	_sort_small_nums(t_ps *ps)
{
	int		num;
	int		top;
	int		middle;

	middle = ps->size_a / 2;
	puts("---------");
	while (1)
	{
		num = _get_smallest_num(ps);
		while (1)
		{
			top = _get_first_element(&ps->s_a);
			if (num == top)
			{
				_pb_(ps);
				break;
			}
			else if (ps->idx <= middle)
				_ra_(ps);
			else if (ps->idx > middle)
				_rra_(ps);
		}
		if (_get_size_(&ps->s_a) == 3)
			break;
	}
	_sort_three_nums(ps);
	while (_get_size_(&ps->s_b))
		_pa_(ps);
	puts("---------");
}

void	_sorting_the_stack_(t_ps *ps)
{
	if (ps->size_a == 2 && ps->s_a->num > ps->s_a->next->num)
		_sa_(ps);
	if (ps->size_a == 3)
		_sort_three_nums(ps);
	else if (ps->size_a > 3 && ps->size_a <= 10)
		_sort_small_nums(ps);
	else if (ps->size_a > 10)
		return ;
}



void	_the_start_(t_ps *ps)
{
	_fill_stack_(ps);
	_sorting_the_stack_(ps);
}

int		_get_size_of_tab(char **ch)
{
	int size;

	size = -1;
	if (ch)
		while (ch[++size]);
	return (size);
}

int		_get_args_size(t_ps *ps, char **args, int argc)
{
	int size;

	if (argc < 2)
		return (1);
	ps->i = 1;
	size = 0;
	while (ps->i < argc)
	{
		ps->j = -1;
		ps->tmp = _split_all(args[ps->i]);
		if (ps->tmp[0] == '\0')
			return (1);
		while (ps->tmp[++ps->j])
		{
			if (_check_args_(ps->tmp[ps->j]))
				return (1);
			free(ps->tmp[ps->j]);
		}
		free(ps->tmp);
		size += ps->j;
		++ps->i;
	}
	ps->fsize = size + 1;
	return (0);
}

int	_get_args_(t_ps *ps, char **args, int argc)
{
	ps->i = 1;
	ps->idx = 0;
	if (!(ps->argv = (char **)malloc(sizeof(char *) * ps->fsize)))
		return (1);
	while (ps->i < argc)
	{
		ps->j = 0;
		ps->tmp = _split_all(args[ps->i]);
		while (ps->tmp[ps->j])
		{
			ps->argv[ps->idx++] = ft_strdup(ps->tmp[ps->j++]);
			free(ps->tmp[ps->j]);
		}
		free(ps->tmp);
		++ps->i;
	}
	ps->argv[ps->idx] = NULL;
	return (0);
}		




int main(int argc, char **argv)
{
    t_ps *ps;
	int i = -1;

    ps = malloc(sizeof(t_ps));
	ps->err = 0;
	if (_get_args_size(ps, argv, argc) || _get_args_(ps, argv, argc))
		_exit_error_();
	_the_start_(ps);
	puts("array :");
	i = -1;
	while (++i < ps->size_a)
		printf("| %d ", ps->array[i]);
	puts("");
	puts("Stack a");
	while (ps->s_a)
	{
		printf("- %d ", ps->s_a->num);
		ps->s_a = ps->s_a->next;
	}
	puts("\nb :");
	while (ps->s_b)
	{
		printf("- %d ", ps->s_b->num);
		ps->s_b = ps->s_b->next;
	}
    free(ps);
    return (0);						
}
