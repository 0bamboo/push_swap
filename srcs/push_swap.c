/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:15:37 by abdait-m          #+#    #+#             */
/*   Updated: 2021/06/25 21:48:11 by abdait-m         ###   ########.fr       */
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
		if (tmp > MAX_INT || tmp < MIN_INT)
			_exit_error_();
		ps->array[j++] = tmp;
		_push_back_(&ps->s_a, tmp);
		i++;
	}
	if (_check_dup_(&ps->s_a))
		_exit_error_();
	_sorting_the_array_(ps);
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
	// printf("|%d|", first->num);
	// printf("|%d|", second->num);
	// printf("|%d|", third->num);
}

void	_start_sorting_stack_(t_ps *ps)
{
	if (ps->size_a == 2 && ps->s_a->num > ps->s_a->next->num)
		_sa_(ps);
	if (ps->size_a == 3)
		_sort_three_nums(ps);
	else if (ps->size_a > 3 && ps->size_a <= 10)
	
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
	_start_sorting_stack_(ps);
}

int		_get_size_of_tab(char **ch)
{
	int size;

	size = -1;
	if (ch)
		while (ch[++size]);
	return (size);
}

char	**_realloc_of_char_(char **tab, int size, int index, int ret)
{
	int i;
	int j;
	char **new;

	i = -1;
	j = 0;
	new = (char **)malloc(sizeof(char *) * size);
	if (tab)
	{
		if(index > 0)
		{
			while(++i < ret)
			{
				printf("+%s+\n", tab[i]);
				new[j++] = ft_strdup(tab[i]);
			}
		}
	}
	i = -1;
	if (index > 0)
		while (new[++i])
			printf("new = |%s|\n", new[i]);
	return (new);
}

void	_get_args_(char **args, int argc)
{
	int i;
	int	j;
	int indx;
	char **tmp;
	char **tab;
	int size;
	int size1;
	int ret;

	i = 1;
	ret = 0;
	size = argc;
	tab = (char **)malloc(sizeof(char *) * size);
	indx = 0;
	while (i < argc)
	{
		j = 0;
		tmp = ft_split(args[i], ' ');
		size1 = _get_size_of_tab(tmp);
		if (size1 > 1)
		{
			size += size1 - 1;
			tab = _realloc_of_char_(tab, size, indx, ret);
		}
		while (tmp[j])
			tab[indx++] = tmp[j++];
		ret += j;
		++i;
	}
	printf("size = |%d|\n", size);
	tab[indx] = NULL;
	i = 0;
	puts("tab :");
	while (tab[i])
		printf("|%s| ", tab[i++]);
	puts("");
}

int main(int argc, char **argv)
{
    t_ps *ps;
	int i = -1;

    ps = malloc(sizeof(t_ps));
	ps->err = 0;
	printf("argc = |%d|\n", argc);
	_get_args_(argv, argc);
	if (_check_args_(argv, argc))
		_exit_error_();
	_the_start_(ps, argc, argv);
	puts("array :");
	while (++i < ps->size_a)
		printf("| %d ", ps->array[i]);
	puts("");
	puts("Stack");
	while (ps->s_a)
	{
		printf("- %d ", ps->s_a->num);
		ps->s_a = ps->s_a->next;
	}
    free(ps);
    return (0);
}
