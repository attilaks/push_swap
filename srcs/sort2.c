/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:21:12 by jwillem-          #+#    #+#             */
/*   Updated: 2019/02/20 22:05:21 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	filling_b_by_blocks(t_stack *stk, int *blocks, int *i)
{
	int	pivot_a;
	int	start_alen;

	
	pivot_a = find_pivot(stk->a, stk->alen);
	start_alen = stk->alen;
	if (stk->blen > 3)
	{
		while (stk->alen != start_alen / 2)
			if (stk->a[0] >= pivot_a)
				ps_push_b(stk, 1);
			else
				ps_rotate(stk, "ra", 1);
		blocks[*i++] = start_alen - stk->alen;
	}
	if (stk->alen > 3)
		filling_b_by_blocks(stk, blocks, i);
	else
	{
		*i--;
		sort_first_top_a(stk);
	}
}

void	sort_first_top_a(t_stack *stk)
{
	if (stk->alen == 2)
		if (A(0) > A(1))
			ps_swap(stk, "sa", 1);
	else
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
	// stk->sorted += stk->alen;
}

void	sort_top_b_block(t_stack *stk, int *blocks, int *i)
{
	if (blocks[*i] > 2)
		push_or_rotate_b(stk, &blocks[*i]);
	else
	{
		while (blocks[*i]-- > 0)
			ps_push_a(stk, 1);
		*i--;
	}
}

void	push_or_rotate_b(t_stack *stk, int *block_len)
{
	int	block_pivot;
	int	rotates;
	int	start_len;

	rotates = 0;
	start_len = (*block_len % 2 ? *block_len + 1 : *block_len);
	block_pivot = find_pivot(stk->b, *block_len);
	while (*block_len != start_len / 2)
		if (B(0) < block_pivot)
		{
			ps_push_a(stk, 1);
			*block_len--;
		}
		else
		{
			ps_rotate(stk, "rb", 1);
			rotates++;
		}
	while (rotates-- > 0)
		ps_rotate(stk, "rrb", 1);
}

void	sort_pushed_to_a(t_stack *stk, int *blocks, int *i)
{
	int	pivot_pushed;
	int	rotate;
	int	sort_cluster;
	
	rotate = 0;
	sort_cluster = stk->alen - stk->sorted;
	pivot_pushed = find_pivot(stk->a, sort_cluster);	
	if (stk->alen - stk->sorted == 2)
		if (A(0) > A(1))
			ps_swap(stk, "sa", 1);
	else
		while (stk->alen  - stk->sorted != sort_cluster / 2)
			if (stk->a[0] >= pivot_pushed)
			{
				ps_push_b(stk, 1);
				blocks[*i]++;
			}
			else
			{
				ps_rotate(stk, "ra", 1);
				rotate++;
			}
	while (rotate-- > 0)
		ps_rotate(stk, "rra", 1);
		// blocks[*i++] = start_alen - stk->alen;
}

// void	handle_block_b_remains(t_stack *stk, int *block_len)
// {
// 	if (*block_len == 2)
// 		if (B(0) < B(1))
// 			ps_swap(stk, "sb", 1);
// 	else if (*block_len == 3)
// 		if (B(0) < B(1) && B(1) > B(2) && B(0) > B(2)
// 			ps_swap(stk, "sb", 1);
// 		else if (B(0) < B(1) && B(1) > B(2) && B(0) < B(2))
// 			ps_rotate(stk, "rb", 1);
// 		else if (B(0) > B(1) && B(1) < B(2) && B(0) < B(2))
// 			ps_rev_rotate(stk, "rrb", 1);
// 		else if (B(0) < B(1) && B(1) < B(2) && B(0) < B(2))
// 			{
// 				ps_swap(stk, "sb", 1);
// 				ps_rev_rotate(stk, "rrb", 1);
// 			}
// 	while (*block_len > 0)
// 		ps_push_a(stk, 1);
// }
