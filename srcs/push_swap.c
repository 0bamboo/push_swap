/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:15:37 by abdait-m          #+#    #+#             */
/*   Updated: 2021/06/28 11:32:47 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../header/push_swap.h"



void	_fill_stack_(t_ps *ps)
{
	int		i;
	long	tmp;

	i = 0;
	ps->s_a = NULL;
	ps->s_b = NULL;
	if((ps->size_a = ps->fsize - 1) == 1)
		exit(0);
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
}

void	_the_start_(t_ps *ps)
{
	_fill_stack_(ps);
	_sorting_the_stack_(ps);
}



int main(int argc, char **argv)
{
    t_ps *ps;
	// int i = -1;

    ps = malloc(sizeof(t_ps));
	ps->err = 0;
	if (_get_args_size(ps, argv, argc) || _get_args_(ps, argv, argc))
		_exit_error_();
	_the_start_(ps);
	// puts("array :");
	// i = -1;
	// while (++i < ps->size_a)
	// 	printf("| %d ", ps->array[i]);
	// puts("");
	// puts("Stack a");
	// while (ps->s_a)
	// {
	// 	printf("- %d ", ps->s_a->num);
	// 	ps->s_a = ps->s_a->next;
	// }
	// puts("\nb :");
	// while (ps->s_b)
	// {
	// 	printf("- %d ", ps->s_b->num);
	// 	ps->s_b = ps->s_b->next;
	// }
    free(ps);
    return (0);						
}
