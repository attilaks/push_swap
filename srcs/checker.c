/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:15:57 by jwillem-          #+#    #+#             */
/*   Updated: 2019/03/03 04:45:26 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		do_operation(t_stack *stacks, char *line)
{
	if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "sb") || \
		!ft_strcmp(line, "ss"))
		ps_swap(stacks, line, 0);
	else if (!ft_strcmp(line, "pa"))
		ps_push_a(stacks, 0);
	else if (!ft_strcmp(line, "pb"))
		ps_push_b(stacks, 0);
	else if (!ft_strcmp(line, "ra") || !ft_strcmp(line, "rb") || \
		!ft_strcmp(line, "rr"))
		ps_rotate(stacks, line, 0);
	else if (!ft_strcmp(line, "rra") || !ft_strcmp(line, "rrb") || \
		!ft_strcmp(line, "rrr"))
		ps_rev_rotate(stacks, line, 0);
	else
		put_error("error");
	// print_stack(stacks);
}

static void	get_sort_instructions(t_stack *stacks, int index)
{
	char	*line;

	// print_stack(stacks);
	if (index == 2)
		visualization(stacks);
	else
		while (get_next_line(0, &line) == 1)
			do_operation(stacks, line);
	print_stack(stacks);
}

void		check_sort(t_stack *stacks, int num_quant)
{
	int	i;

	i = 0;
	if (stacks->blen != 0 || stacks->alen != num_quant)
		put_error("ko");
	while (i < stacks->alen - 1)
	{
		if (stacks->a[i] > stacks->a[i + 1])
			put_error("ko");
		i++;
	}
	ft_printf("OK\n");
}

int			main(int ac, char **av)
{
	t_stack	stacks;
	char	**split;
	int		index;

	stacks.alen = 0;
	stacks.blen = 0;
	split = NULL;
	index = ft_strcmp(av[1], "-v") ? 1 : 2;
	if ((ac == 2 && index == 1) || (ac == 3 && index == 2))
	{
		split = ft_strsplit(av[index], ' ');
		stack_memory(&stacks, split_len(split));
		validate_and_rec_split(&stacks, split_len(split), split);
		get_sort_instructions(&stacks, index);
	}
	else if ((ac > 2 && index == 1) || (ac > 3 && index == 2))
	{
		stack_memory(&stacks, ac - 1);
		validate_and_rec(&stacks, ac, av);
		get_sort_instructions(&stacks, index);
	}
	check_sort(&stacks, stacks.alen + stacks.blen);
	return (0);
}
