/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 04:07:51 by jwillem-          #+#    #+#             */
/*   Updated: 2019/03/01 18:53:32 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	freesplit(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return ;
}

int			split_len(char **split)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (split[i++])
		len++;
	return (len);
}

void		validate_and_rec_split(t_stack *stk, int numbers, char **split)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (i < numbers)
	{
		stk->a[i] = ft_atoi(split[i]);
		str = ft_itoa(stk->a[i]);
		if (ft_strcmp(str, split[i]))
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
	freesplit(split);
}
