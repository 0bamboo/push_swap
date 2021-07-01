/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 10:59:56 by abdait-m          #+#    #+#             */
/*   Updated: 2021/07/01 12:40:40 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	*ps;

	ps = malloc(sizeof(t_ps));
	_init_vars_(ps);
	if (argc < 2)
		exit(0);
	if (_get_args_size(ps, argv, argc) || _get_args_(ps, argv, argc))
		_exit_error_(ps);
	_fill_stack_(ps, 0);
	while (get_next_line(0, &ps->input))
	{
		if (_check_line_(ps))
			_exit_error_(ps);
		free(ps->input);
	}
	_check_if_stack_sorted_(ps);
	_clear_all_(ps);
}
