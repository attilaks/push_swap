/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:09:56 by jwillem-          #+#    #+#             */
/*   Updated: 2019/03/01 19:43:35 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			check_sorted(t_stack *stk)
{
	int	sorted;
	int	i;

	if (stk->alen + stk->blen == 0)
		return (0);
	sorted = 1;
	i = -1;
	while (++i < stk->alen - 1)
	{
		if (stk->a[i] < stk->a[i + 1])
			sorted++;
		else
			break ;
	}
	return (sorted);
}

static void	filling_b_by_blocks(t_stack *stk, int *blocks, int *i)
{
	int	pivot_a;
	int	low_pivot;
	int	start_alen;

	pivot_a = find_pivot(stk->a, stk->alen);
	low_pivot = find_low_pivot(stk->a, pivot_a, stk->alen);
	start_alen = (stk->alen % 2 ? stk->alen + 1 : stk->alen);
	blocks[*i] = stk->alen / 2;
	while (stk->alen != start_alen / 2)
		if (stk->a[0] < pivot_a)
			ps_push_b(stk, 1);
		else if (A(stk->alen - 1) < pivot_a)
		{
			if (B(stk->blen - 1) >= low_pivot && stk->blen > 1 && *i == 0)
				ps_rev_rotate(stk, "rrr", 1);
			else
				ps_rev_rotate(stk, "rra", 1);
		}
		else if (stk->b[0] < low_pivot && stk->blen > 1 && *i == 0)
			ps_rotate(stk, "rr", 1);
		else
			ps_rotate(stk, "ra", 1);
	(*i)++;
}

static void	sort_stack(t_stack *stk)
{
	int	*blocks;
	int	i;

	blocks = ft_memalloc(33);
	i = 0;
	if (check_sorted(stk) != stk->alen + stk->blen)
	{
		while (stk->alen > 3)
			filling_b_by_blocks(stk, blocks, &i);
		i--;
		sort_first_top_a(stk);
		while ((stk->sorted = check_sorted(stk)) != stk->alen + stk->blen \
			&& i >= 0)
		{
			sort_top_b_block(stk, blocks, &i);
			sort_pushed_to_a(stk, blocks, &i);
		}
	}
	free(blocks);
}

int			main(int ac, char **av)
{
	t_stack	stk;
	char	**split;

	stk.alen = 0;
	stk.blen = 0;
	stk.sorted = 0;
	split = NULL;
	if (ac == 2)
	{
		split = ft_strsplit(av[1], ' ');
		stack_memory(&stk, split_len(split));
		validate_and_rec_split(&stk, split_len(split), split);
	}
	else if (ac > 2)
	{
		stack_memory(&stk, ac - 1);
		validate_and_rec(&stk, ac, av);
	}
	sort_stack(&stk);
	return (0);
}
