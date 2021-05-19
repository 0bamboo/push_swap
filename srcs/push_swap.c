/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:15:37 by abdait-m          #+#    #+#             */
/*   Updated: 2021/05/19 15:10:03 by abdait-m         ###   ########.fr       */
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
	_swap_(&ps->s_a, 'a');
	_push_to_stack_(ps, 'b');
	_push_to_stack_(ps, 'b');
	_push_to_stack_(ps, 'b');
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
