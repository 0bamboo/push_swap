/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:15:37 by abdait-m          #+#    #+#             */
/*   Updated: 2021/07/02 11:15:35 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	*ps;

	ps = malloc(sizeof(t_ps));
	if (!ps)
		return (1);
	_init_vars_(ps);
	if (argc < 2 || _get_args_size(ps, argv, argc)
		|| _get_args_(ps, argv, argc))
		_exit_error_(ps);
	_the_start_(ps);
	_clear_all_(ps);
	return (0);
}
