/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_the_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 00:32:01 by abdait-m          #+#    #+#             */
/*   Updated: 2021/06/20 00:32:01 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	_insertion_sort_(t_ps *ps)
{
	int	i;
	int	tmp;
	int	j;

	i = 0;
	while (++i < ps->size_a)
	{
		tmp = ps->array[i];
		j = i - 1;
		while (j >= 0 && ps->array[j] > tmp)
		{
			ps->array[j + 1] = ps->array[j];
			j = j - 1;
		}
		ps->array[j + 1] = tmp;
	}
}

void	_swap_nums_(int *a, int *b)
{
	int	tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		_partition_(int *array, int left, int right)
{
	int		pivot;
	int		i;
	int		j;

	i = left - 1;
	j = i;
	pivot = array[right];
	while (++j <= right - 1)
	{
		if (array[j] < pivot)
		{
			i++;
			_swap_nums_(&array[i], &array[j]);
		}
	}
	_swap_nums_(&array[i + 1], &array[right]);
	return (i + 1);
}

void	_quick_sort_(int *array, int left, int right)
{
	int		pivot;
	
	if (left < right)
	{
		pivot = _partition_(array, left, right);
		_quick_sort_(array, left, pivot - 1);
		_quick_sort_(array, pivot + 1, right);
	}
}
