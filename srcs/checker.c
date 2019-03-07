/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:15:57 by jwillem-          #+#    #+#             */
/*   Updated: 2019/03/07 23:45:48 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		do_operation(t_stack *stk, char *line)
{
	if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "sb") || \
		!ft_strcmp(line, "ss"))
		ps_swap(stk, line, 0);
	else if (!ft_strcmp(line, "pa"))
		ps_push_a(stk, 0);
	else if (!ft_strcmp(line, "pb"))
		ps_push_b(stk, 0);
	else if (!ft_strcmp(line, "ra") || !ft_strcmp(line, "rb") || \
		!ft_strcmp(line, "rr"))
		ps_rotate(stk, line, 0);
	else if (!ft_strcmp(line, "rra") || !ft_strcmp(line, "rrb") || \
		!ft_strcmp(line, "rrr"))
		ps_rev_rotate(stk, line, 0);
	else
	{
		free(line);
		put_error("error");
	}
	free(line);
}

static void	get_sort_instructions(t_stack *stk, int index)
{
	char	*line;

	if (index == 2)
		visualization(stk);
	else if (index == 1)
		while (get_next_line(0, &line) == 1)
			do_operation(stk, line);
}

void		check_sort(t_stack *stk, int num_quant)
{
	int	i;

	i = 0;
	if (stk->blen != 0 || stk->alen != num_quant)
		put_error("ko");
	while (i < stk->alen - 1)
	{
		if (stk->a[i] > stk->a[i + 1])
			put_error("ko");
		i++;
	}
	ft_printf("OK\n");
}

int			main(int ac, char **av)
{
	t_stack	stk;
	int		index;
	int		quantity;

	if (ac == 1)
		return (0);
	stk.alen = 0;
	stk.blen = 0;
	index = ft_strcmp(av[1], "-v") ? 1 : 2;
	quantity = num_quantity(av);
	stack_memory(&stk, quantity);
	validate_and_rec(&stk, quantity, av);
	get_sort_instructions(&stk, index);
	check_sort(&stk, stk.alen + stk.blen);
	free(stk.a);
	free(stk.b);
	return (0);
}
