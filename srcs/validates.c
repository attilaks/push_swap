/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 01:07:02 by jwillem-          #+#    #+#             */
/*   Updated: 2019/02/28 05:32:16 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	stack_memory(t_stack *stk, int memory)
{
	if (!(stk->a = (int *)malloc(sizeof(int) * memory)) || \
		!(stk->b = (int *)malloc(sizeof(int) * memory)))
		put_error("error");
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
	int		j;
	char	*str;

	i = 0;
	while (i < ac - 1)
	{
		stk->a[i] = ft_atoi(av[i + 1]);
		str = ft_itoa(stk->a[i]);
		if (ft_strcmp(str, av[i + 1]))
		{
			free(str);
			put_error("error");
		}
		free(str);
		j = i;
		while (--j >= 0)
			if (stk->a[i] == stk->a[j])
				put_error("error");
		i++;
		stk->alen++;
	}
}
