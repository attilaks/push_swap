/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 01:07:02 by jwillem-          #+#    #+#             */
/*   Updated: 2019/03/07 23:52:09 by jwillem-         ###   ########.fr       */
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

void	record_split(t_stack *stk, int *ai, char *line)
{
	int		j;
	int		sub_quantity;
	char	**split;
	char	*str;

	j = 0;
	split = ft_strsplit(line, ' ');
	sub_quantity = split_len(split);
	while (j < sub_quantity)
	{
		stk->a[*ai] = ft_atoi(split[j]);
		str = ft_itoa(stk->a[*ai]);
		if (ft_strcmp(str, split[j]))
		{
			free(str);
			put_error("error");
		}
		free(str);
		duplicate_check(stk, *ai);
		(*ai)++;
		j++;
		stk->alen++;
	}
	freesplit(split);
}

void	record_argument(t_stack *stk, int *ai, char *argument)
{
	char	*str;

	stk->a[*ai] = ft_atoi(argument);
	str = ft_itoa(stk->a[*ai]);
	if (ft_strcmp(str, argument))
	{
		free(str);
		put_error("error");
	}
	free(str);
	duplicate_check(stk, *ai);
	stk->alen++;
	(*ai)++;
}

void	validate_and_rec(t_stack *stk, int quantity, char **av)
{
	int		i;
	int		ai;

	i = ft_strcmp(av[1], "-v") ? 1 : 2;
	ai = 0;
	while (ai < quantity)
	{
		if (ft_strchr(av[i], ' '))
			record_split(stk, &ai, av[i]);
		else
			record_argument(stk, &ai, av[i]);
		i++;
	}
}
