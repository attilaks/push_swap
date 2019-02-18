/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:09:56 by jwillem-          #+#    #+#             */
/*   Updated: 2019/02/18 22:00:06 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		find_pivot(int *a, int len)
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
			ft_swap(&tmp[i], tmp[i + 1]);
			i = -1;
		}
	}
	return (tmp[len / 2]);
}

int		check_sorted(t_stack *stk)
{
	int	sorted;
	int	i;

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

void	first_sort(t_stack *stk, int *blocks)
{
	int	pivot;
	int	start_alen;

	pivot = find_pivot(stk->a, stk->alen);
	start_alen = stk->alen;
	while (stk->blen != start_alen / 2)
	{
		if (stk->a[0] < pivot)
			ps_push_b(stk, 1);
		else
			ps_rotate(stk, "ra", 1);
	}
	blocks[0] = stk->alen;
}

void	sort_stack(t_stack *stk)
{
	int	*blocks;
	int	i;

	blocks = ft_memalloc(33);
	i = 1;
	first_sort(stk, blocks);
	filling_a_by_blocks(stk, blocks, &i);
	while (check_sorted(stk) != stk->alen + stk->blen)
	{
		
	}
	free(blocks);
}

int	main(int ac, char *av)
{
	t_stack	stk;

	stk.alen = 0;
	stk.blen = 0;
	if (!(stk.a = (int *)malloc(sizeof(int) * (ac - 1))) || \
		!(stk.b = (int *)malloc(sizeof(int) * (ac - 1))))
		put_error(&stk, "error");
	if (ac > 1)
	{
		validate_and_rec(&stk, ac, av);
		sort_stack(&stk);
	}
	print_stack(&stk);
	free(stk.a);
	free(stk.b);
	return(0);
}
