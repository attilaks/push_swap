/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:15:57 by jwillem-          #+#    #+#             */
/*   Updated: 2019/02/10 15:20:07 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	put_error(t_stack *stacks)
{
	write(2, "Error\n", 6);
	free(stacks->aarr);
	free(stacks->barr);
	exit(1);
}

// void	create_stacks(t_stack *stacks, int ac)
// {
// 	if (!(stacks->aarr = (int *)malloc(sizeof(int) * (ac - 1))) || \
// 		!(stacks->barr = (int *)malloc(sizeof(int) * (ac - 1))))
// 			put_error(stacks);
// }

void	validate_and_rec(t_stack *stacks, int ac, char **av)
{
	int		i;
	char	*str;

	i = 0;
	while (i < ac - 1)
	{
		stacks->aarr[i] = ft_atoi(av[i + 1]);
		str = ft_itoa(stacks->aarr[i]);
		if (ft_strcmp(str, av[i + 1]))
		{
			free(str);
			put_error(stacks);
		}
		free(str);
		i++;
	}
}

void	check_sort(t_stack *stacks)
{

}

int		main(int ac, char **av)
{
	int	i;
	t_stack	stacks;

	i = 0;
	if (ac > 1)
	{
		if (!(stacks.aarr = (int *)malloc(sizeof(int) * (ac - 1))) || \
			!(stacks.barr = (int *)malloc(sizeof(int) * (ac - 1))))
				put_error(&stacks);
		validate_and_rec(&stacks, ac, av);
		check_sort(&stacks);
		free(stacks.aarr);
		free(stacks.barr);
	}
	return (0);
}
