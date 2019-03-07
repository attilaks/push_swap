/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 04:07:51 by jwillem-          #+#    #+#             */
/*   Updated: 2019/03/07 23:52:30 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	freesplit(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return ;
}

int		split_len(char **split)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (split[i++])
		len++;
	return (len);
}

void	put_error(char *error)
{
	if (!ft_strcmp(error, "error"))
		write(2, "Error\n", 6);
	else if (!ft_strcmp(error, "ko"))
		ft_printf("KO\n");
	exit(1);
}

void	duplicate_check(t_stack *stk, int ai)
{
	int	check;

	check = ai;
	while (--check >= 0)
		if (stk->a[ai] == stk->a[check])
			put_error("error");
}

int		num_quantity(char **av)
{
	int		i;
	int		quantity;
	char	**split;

	i = ft_strcmp(av[1], "-v") ? 1 : 2;
	quantity = 0;
	while (av[i])
	{
		if (ft_strchr(av[i], ' '))
		{
			split = ft_strsplit(av[i], ' ');
			quantity += split_len(split);
			freesplit(split);
		}
		else
			quantity++;
		i++;
	}
	return (quantity);
}
