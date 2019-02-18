/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:14:30 by jwillem-          #+#    #+#             */
/*   Updated: 2019/02/18 21:52:13 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	filling_a_by_blocks(t_stack *stk, int *blocks, int *i)
{
	int	pivot;
	int	start_blen;

	pivot = find_pivot(stk->b, stk->blen);
	start_blen = stk->blen;
	while (stk->blen != start_blen / 2)
		if (stk->b[0] >= pivot)
			ps_push_a(stk, 1);
		else
			ps_rotate(stk, "rb", 1);
	blocks[*i++] = start_blen - stk->blen;
	if (stk->blen > 3)
		filling_a_by_blocks(stk, blocks, i);
	else
		while (stk->blen != 0)
		{
			ps_push_a(stk, 1);
			blocks[*i] += 1;
		}
}
