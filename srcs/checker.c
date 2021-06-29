/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 10:59:56 by abdait-m          #+#    #+#             */
/*   Updated: 2021/06/29 11:30:20 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int main(int argc, char **argv)
{
    t_ps *ps;

    ps = malloc(sizeof(t_ps));
    _init_vars_(ps);
    if (argc < 2)
        exit(0);
    if (_get_args_size(ps, argv, argc) || _get_args_(ps, argv, argc))
        _exit_error_(ps);
}


