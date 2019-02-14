/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:15:57 by jwillem-          #+#    #+#             */
/*   Updated: 2019/02/14 19:38:14 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		put_error(t_stack *stacks, char *error)
{
	if (!ft_strcmp(error, "error"))
		write(2, "Error\n", 6);
	else if (!ft_strcmp(error, "ko"))
		ft_printf("KO\n");
	free(stacks->a);
	free(stacks->b);
	exit(1);
}

static void	get_sort_instructions(t_stack *stacks)
{
	char	*line;

	print_stack(stacks);
	while (get_next_line(0, &line) == 1)
	{
		if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "sb") || \
			!ft_strcmp(line, "ss"))
			ps_swap(stacks, line);
		else if (!ft_strcmp(line, "pa"))
			ps_push_a(stacks);
		else if (!ft_strcmp(line, "pb"))
			ps_push_b(stacks);
		else if (!ft_strcmp(line, "ra") || !ft_strcmp(line, "rb") || \
			!ft_strcmp(line, "rr"))
			ps_rotate(stacks, line);
		else if (!ft_strcmp(line, "rra") || !ft_strcmp(line, "rrb") || \
			!ft_strcmp(line, "rrr"))
			ps_rev_rotate(stacks, line);
		else
			put_error(stacks, "error");
		print_stack(stacks);
	}
}

void		validate_and_rec(t_stack *stacks, int ac, char **av)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (i < ac - 1)
	{
		stacks->a[i] = ft_atoi(av[i + 1]);
		str = ft_itoa(stacks->a[i]);
		if (ft_strcmp(str, av[i + 1]))
		{
			free(str);
			put_error(stacks, "error");
		}
		free(str);
		j = i;
		while (--j >= 0)
			if (stacks->a[i] == stacks->a[j])
				put_error(stacks, "error");
		i++;
		stacks->alen++;
	}
}

static void	check_sort(t_stack *stacks, int num_quant)
{
	int	i;

	i = 0;
	if (stacks->blen != 0 || stacks->alen != num_quant)
		put_error(stacks, "ko");
	while (i < stacks->alen)
	{
		if (stacks->a[i] < stacks->a[i - 1])
			put_error(stacks, "ko");
		i++;
	}
	ft_printf("OK\n");
}

int			main(int ac, char **av)
{
	t_stack	stacks;

	stacks.alen = 0;
	stacks.blen = 0;
	if (!(stacks.a = (int *)malloc(sizeof(int) * (ac - 1))) || \
		!(stacks.b = (int *)malloc(sizeof(int) * (ac - 1))))
		put_error(&stacks, "error");
	if (ac > 1)
	{
		validate_and_rec(&stacks, ac, av);
		get_sort_instructions(&stacks);
		check_sort(&stacks, ac - 1);
	}
	free(stacks.a);
	free(stacks.b);
	return (0);
}
