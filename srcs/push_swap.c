/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:15:37 by abdait-m          #+#    #+#             */
/*   Updated: 2021/05/15 15:58:24 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/push_swap.h"

typedef struct  s_stack
{
    int             val;
    int             top;
    struct s_stack  *next;   
    struct s_stack  *prev;   
}               t_stack;

void    _push_(t_stack *st)
{

}

void    _pop_(t_stack *st)
{
    
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    printf("push swap \n");
    return (0);
}
