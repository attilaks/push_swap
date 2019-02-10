/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:15:57 by jwillem-          #+#    #+#             */
/*   Updated: 2019/02/10 20:12:51 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		put_error(t_stack *stacks, char *error)
{
	if (!ft_strcmp(error, "error"))
		write(2, "Error\n", 6);
	else if (!ft_strcmp(error, "ko"))
		ft_printf("KO\n");	
	free(stacks->aarr);
	free(stacks->barr);
	exit(1);
}

int			is_duplicate(int *aarr, int i)
{
	int	j;
	
	j = i;
	while (--i >= 0)
		if (aarr[j] == aarr[i])
			return (1);
	return (0);
}

void		validate_and_rec(t_stack *stacks, int ac, char **av)
{
	int		i;
	char	*str;

	i = 0;
	while (i < ac - 1)
	{
		stacks->aarr[i] = ft_atoi(av[i + 1]);
		str = ft_itoa(stacks->aarr);
		if (ft_strcmp(str, av[i + 1]) || is_duplicate(stacks->aarr, i))
		{
			free(str);
			put_error(stacks, "error");
		}
		free(str);
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
		if (stacks->aarr[i] < stacks->aarr[i - 1])
			put_error(stacks, "ko");
		i++;
	}
	ft_printf("OK\n");
}

int		main(int ac, char **av)
{
	int	i;
	t_stack	stacks;

	i = 0;
	stacks.alen = 0;
	stacks.blen = 0;
	if (!(stacks.aarr = (int *)malloc(sizeof(int) * (ac - 1))) || \
		!(stacks.barr = (int *)malloc(sizeof(int) * (ac - 1))))
			put_error(&stacks, "error");
	if (ac > 1)
	{		
		validate_and_rec(&stacks, ac, av);
		get_sort_instructions(&stacks);
		check_sort(&stacks, ac - 1);
	}
	free(stacks.aarr);
	free(stacks.barr);
	return (0);
}
