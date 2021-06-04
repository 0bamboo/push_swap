/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:16:31 by abdait-m          #+#    #+#             */
/*   Updated: 2021/06/04 01:30:00 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H    

# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

#define MAX_INT 2147483647
#define MIN_INT -2147483648

typedef struct  s_stack
{
    int             num;
    int             top;
    struct s_stack  *next;   
    struct s_stack  *prev;   
}               t_stack;

typedef struct  s_ps
{
	t_stack		*s_a;
	t_stack		*s_b;
    int         err;
    int         *array;
    int         size_a;
    int         size_b;
}				t_ps;

void    _push_front_(t_stack **st, int num);
void	_push_back_(t_stack **st, int num);
void	_swap_(t_stack **st);
void    _pop_front_(t_stack **st);
void	_pop_back_(t_stack **st);
void	_push_to_stack_(t_ps *ps, char rule);
int	    _checker_(char *args, int index);
int	    _check_dup_(t_stack **s_a, int size);
int     _check_args_(char **args, int size);
long	_atoi_mod_(const char *str);
void    _empty_stack_(t_stack *st);
void	_exit_error_(void);
int		_get_last_element_(t_stack **st);
int	    _get_size_(t_stack **st);
void	_reverse_rotate_(t_ps *ps, char rule);
void	_rotate_(t_ps *ps, char rule);
void	_fill_stack_(t_ps *ps, char **args, int size);
void    _ra_(t_ps *ps);
void    _rb_(t_ps *ps);
void    _rr_(t_ps *ps);
void    _rra_(t_ps *ps);
void    _rrb_(t_ps *ps);
void    _rrr_(t_ps *ps);
void    _pa_(t_ps *ps);
void    _pb_(t_ps *ps);
void    _sa_(t_ps *ps);
void    _sb_(t_ps *ps);
void    _ss_(t_ps *ps);

#endif