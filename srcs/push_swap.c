/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:15:37 by abdait-m          #+#    #+#             */
/*   Updated: 2021/05/18 14:59:26 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/push_swap.h"

void    _push_front_(t_stack **st, int num)
{
    t_stack *curr;

    curr = malloc(sizeof(t_stack));
    curr->prev = NULL;
    curr->num = num;
    if ((*st))
    {
        curr->next = (*st);
        (*st)->prev = curr;
		(*st) = curr;
    }
    else
    {
        curr->next = NULL;
        (*st) = curr;
    }
}

void	_push_back_(t_stack **st, int num)
{
	t_stack	*curr;
	t_stack	*head;

	head = (*st);
	curr = malloc(sizeof(t_stack));
	curr->prev = NULL;
	curr->num = num;
	curr->next = NULL;
	if (!head)
		(*st) = curr;
	else
	{
		while (head->next)
			head = head->next;
		head->next = curr;
		curr->prev = head;
	}
}

void	_swap_(t_stack **st, int size, char c)
{
	t_stack *curr;
	t_stack *tmp;
	int		t;

	if (size < 2)
		return ;
	curr = (*st);
	tmp = curr->next;
	t = tmp->num;
	tmp->num = curr->num;
	curr->num = t;
	if (c == 'a')
		puts("sa");
	else
		puts("sb");
}

// void	_rotate_(t_stack **st, int size)
// {
	
// }

// void	_push_to_stack_(t_ps *ps, char *rule)
// {
	
// }
// void    _pop_(t_stack *st, int num)
// {
//     printf("pop");
// }

int	_checker_(char *args, int index)
{
	if (((args[0] != '-' && args[0] != '+') && !ft_isdigit(args[index]))
			|| ((args[0] == '-' || args[0] == '+') && !ft_isdigit(args[1])))
		return (1);
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

void    _empty_stack_(t_stack *st)
{
    t_stack *tmp;
    while (st)
    {
        tmp = st;
        st = st->next;
        free(tmp);
    }
}

void	_fill_stack_(t_ps *ps, char **args, int size)
{
	int	i;

	i = 1;
	ps->s_a = NULL;
	_swap_(&ps->s_a, 0, 'a');
	while (i < size)
	{
		_push_back_(&ps->s_a, ft_atoi(args[i]));
		i++;
	}
	_swap_(&ps->s_a, 4, 'a');
	// _swap_(&ps->s_a, 4);
	while(ps->s_a)
	{
		// printf("hi");
		printf("%d ", ps->s_a->num);
		ps->s_a = ps->s_a->next;
	}
}

int main(int argc, char **argv)
{
    t_ps *ps;

    ps = malloc(sizeof(t_ps));
	if (_check_args_(argv, argc))
	{
		printf("Error\n");
		exit (0);
	}
	_fill_stack_(ps, argv, argc);
    free(ps);
    return (0);
}
