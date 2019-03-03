/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivots.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 00:57:41 by jwillem-          #+#    #+#             */
/*   Updated: 2019/02/28 05:46:17 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			find_low_pivot(int *a, int pivot, int len)
{
	int	*tmp;
	int	i;
	int	tmp_len;
	int	t;

	i = -1;
	t = 0;
	tmp_len = len / 2;
	if (!(tmp = (int *)malloc(sizeof(int) * tmp_len)))
		put_error("error");
	while (++i < len)
		if (a[i] < pivot)
			tmp[t++] = a[i];
	i = -1;
	while (++i < tmp_len - 1)
	{
		if (tmp[i] > tmp[i + 1])
		{
			ft_swap(&tmp[i], &tmp[i + 1]);
			i = -1;
		}
	}
	t = tmp[tmp_len / 2];
	free(tmp);
	return (t);
}

int			find_pivot(int *a, int len)
{
	int	tmp[len];
	int	i;

	i = -1;
	while (++i < len)
		tmp[i] = a[i];
	i = -1;
	while (++i < len - 1)
	{
		if (tmp[i] > tmp[i + 1])
		{
			ft_swap(&tmp[i], &tmp[i + 1]);
			i = -1;
		}
	}
	return (tmp[len / 2]);
}
