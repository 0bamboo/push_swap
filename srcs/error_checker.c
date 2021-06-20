/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:44:02 by abdait-m          #+#    #+#             */
/*   Updated: 2021/06/20 00:18:38 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	_checker_(char *args, int index)
{
	//fix error -3+3 maybe fixed but check for other errors and try to recode this shitt code 
	if (((args[0] != '-' && args[0] != '+') && !ft_isdigit(args[index]))
			|| (index != 0 && !ft_isdigit(args[index])))
		return (1);
	return (0);
}

int	_check_dup_(t_stack **s_a)
{
	t_stack	*curr;
	t_stack	*check;
	int		tmp;
	int		i;

	curr = (*s_a);
	i = 0;
	if (curr)
	{
		while (curr)
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
