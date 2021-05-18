/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:16:31 by abdait-m          #+#    #+#             */
/*   Updated: 2021/05/18 01:08:14 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H    

# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

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
}				t_ps;

#endif