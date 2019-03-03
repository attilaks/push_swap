/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:21:12 by jwillem-          #+#    #+#             */
/*   Updated: 2019/03/01 18:28:24 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	push_or_rotate_b(t_stack *stk, int *blocks, int *i)
{
	int	block_pivot;
	int	rotates;
	int	start_len;

	rotates = 0;
	start_len = blocks[*i];
	block_pivot = find_pivot(stk->b, blocks[*i]);
	while (blocks[*i] != start_len / 2)
		if (B(0) >= block_pivot)
		{
			ps_push_a(stk, 1);
			blocks[*i]--;
		}
		else
		{
			ps_rotate(stk, "rb", 1);
			rotates++;
		}
	if (*i != 0)
		while (rotates-- > 0)
			ps_rev_rotate(stk, "rrb", 1);
}

static void	push_back_to_b(t_stack *stk, int *blocks, int *i)
{
	int	rotates;
	int	pivot_pushed;
	int	sort_cluster;

	rotates = 0;
	sort_cluster = (stk->alen - stk->sorted) % 2 ? \
					stk->alen - stk->sorted + 1 : stk->alen - stk->sorted;
	pivot_pushed = find_pivot(stk->a, stk->alen - stk->sorted);
	while (stk->alen - stk->sorted != sort_cluster / 2)
		if (A(0) < pivot_pushed)
		{
			ps_push_b(stk, 1);
			blocks[*i]++;
		}
		else
		{
			ps_rotate(stk, "ra", 1);
			rotates++;
		}
	while (rotates-- > 0)
		ps_rev_rotate(stk, "rra", 1);
	if (stk->alen - stk->sorted <= 2)
		sort_pushed_to_a(stk, blocks, i);
}

void		sort_first_top_a(t_stack *stk)
{
	if (stk->alen == 2)
	{
		if (A(0) > A(1))
			ps_swap(stk, "sa", 1);
	}
	else
	{
		if (A(0) < A(1) && A(1) > A(2) && A(0) < A(2))
		{
			ps_swap(stk, "sa", 1);
			ps_rotate(stk, "ra", 1);
		}
		else if (A(0) > A(1) && A(1) < A(2) && A(0) < A(2))
			ps_swap(stk, "sa", 1);
		else if (A(0) < A(1) && A(1) > A(2) && A(0) > A(2))
			ps_rev_rotate(stk, "rra", 1);
		else if (A(0) > A(1) && A(1) < A(2) && A(0) > A(2))
			ps_rotate(stk, "ra", 1);
		else if (A(0) > A(1) && A(1) > A(2) && A(0) > A(2))
		{
			ps_rotate(stk, "ra", 1);
			ps_swap(stk, "sa", 1);
		}
	}
}

void		sort_top_b_block(t_stack *stk, int *blocks, int *i)
{
	if (blocks[*i] > 2)
		push_or_rotate_b(stk, blocks, i);
	else
	{
		while (blocks[*i]-- > 0)
			ps_push_a(stk, 1);
		(*i)--;
	}
}

void		sort_pushed_to_a(t_stack *stk, int *blocks, int *i)
{
	if (stk->alen - stk->sorted == 2)
	{
		if (A(0) > A(1))
		{
			if (B(0) < B(1) && blocks[*i] > 1)
				ps_swap(stk, "ss", 1);
			else
				ps_swap(stk, "sa", 1);
		}
	}
	else if (stk->alen - stk->sorted == 3)
		sort_top_three_a(stk);
	else if (stk->alen - stk->sorted > 3)
	{
		(*i)++;
		blocks[*i] = 0;
		push_back_to_b(stk, blocks, i);
	}
	if (check_sorted(stk) != stk->alen)
		sort_pushed_to_a(stk, blocks, i);
}
