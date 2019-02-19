/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:14:30 by jwillem-          #+#    #+#             */
/*   Updated: 2019/02/19 21:14:03 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	filling_a_by_blocks(t_stack *stk, int *blocks, int *i)
{
	int	pivot_b;
	int	start_blen;

	
	pivot_b = find_pivot(stk->b, stk->blen);
	start_blen = stk->blen;
	if (stk->blen > 3)
	{
		while (stk->blen != start_blen / 2)
			if (stk->b[0] >= pivot_b)
				ps_push_a(stk, 1);
			else
				ps_rotate(stk, "rb", 1);
		blocks[*i++] = start_blen - stk->blen;
	}
	if (stk->blen > 3)
		filling_a_by_blocks(stk, blocks, i);
	else
		handle_b_remains(stk, blocks, i);
}

void	handle_b_remains(t_stack *stk, int *blocks, int *i)
{
	if (blocks[*i] == 2)
		if (stk->b[0] < stk->b[1])
			ps_swap(stk, "sb", 1);
	else if (blocks[*i] == 3)
		if (stk->b[0] < stk->b[1] && stk->b[1] > stk->b[2] \
			&& stk->b[0] > stk->b[2])
			ps_swap(stk, "sb", 1);
		else if (stk->b[0] < stk->b[1] && stk->b[1] > stk->b[2] \
			&& stk->b[0] < stk->b[2])
			ps_rotate(stk, "rb", 1);
		else if (stk->b[0] > stk->b[1] && stk->b[1] < stk->b[2] \
			&& stk->b[0] < stk->b[2])
			ps_rev_rotate(stk, "rrb", 1);
		else if (stk->b[0] < stk->b[1] && stk->b[1] < stk->b[2] \
			&& stk->b[0] < stk->b[2])
			{
				ps_swap(stk, "sb", 1);
				ps_rev_rotate(stk, "rrb", 1);
			}
	while (stk->blen != 0)
		ps_push_a(stk, 1);
}


void	sort_first_top_of_a(t_stack *stk, int *blocks, int *i)
{
	int	rotate;
	
	rotate = blocks[*i];
	if (blocks[*i] == 3)
		if (stk->a[0] > stk->a[1] && stk->a[1] < stk->a[2] \
			&& stk->a[0] < stk->a[2])
			ps_swap(stk, "sa", 1);
	while (rotate-- != 0)
		ps_rotate(stk, "ra", 1);
	*i--;
}

void	sort_top_a_block(t_stack *stk, int *blocks, int *i)
{
	if (blocks[*i] == 3)
	{
		sort_top_three_a(stk);
		*i--;
	}
	
}
