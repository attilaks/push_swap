/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 01:07:02 by jwillem-          #+#    #+#             */
/*   Updated: 2019/03/05 21:30:01 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	stack_memory(t_stack *stk, int memory)
{
	if (memory != 0)
	{
		if (!(stk->a = (int *)malloc(sizeof(int) * memory)) || \
			!(stk->b = (int *)malloc(sizeof(int) * memory)))
			put_error("error");
	}
	else
	{
		stk->a = NULL;
		stk->b = NULL;
	}
}

void	put_error(char *error)
{
	if (!ft_strcmp(error, "error"))
		write(2, "Error\n", 6);
	else if (!ft_strcmp(error, "ko"))
		ft_printf("KO\n");
	exit(1);
}

void	validate_and_rec(t_stack *stk, int ac, char **av)
{
	int		i;
	int		ai;
	int		j;
	char	*str;

	i = ft_strcmp(av[1], "-v") ? 0 : 1;
	ai = 0;
	while (i < ac - 1)
	{
		stk->a[ai] = ft_atoi(av[i + 1]);
		str = ft_itoa(stk->a[ai]);
		if (ft_strcmp(str, av[i + 1]))
		{
			free(str);
			put_error("error");
		}
		free(str);
		j = ai;
		while (--j >= 0)
			if (stk->a[ai] == stk->a[j])
				put_error("error");
		ai++;
		i++;
		stk->alen++;
	}
}
