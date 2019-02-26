/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:09:56 by jwillem-          #+#    #+#             */
/*   Updated: 2019/02/26 06:20:51 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// static void	check_sort(t_stack *stacks, int num_quant)
// {
// 	int	i;

// 	i = 0;
// 	if (stacks->blen != 0 || stacks->alen != num_quant)
// 		put_error(stacks, "ko");
// 	while (i < stacks->alen - 1)
// 	{
// 		if (stacks->a[i] > stacks->a[i + 1])
// 			put_error(stacks, "ko");			
// 		i++;
// 	}
// 	ft_printf("OK\n");
// }

int			find_upper_pivot(t_stack *stk, int *a, int pivot, int len)
{
	int	*tmp;
	int	i;
	int	tmp_len;
	int	t;

	i = -1;
	t = 0;
	tmp_len = len % 2 ? len / 2 + 1 : len / 2;
	if (!(tmp = (int *)malloc(sizeof(int) * tmp_len)))
		put_error(stk, "error");
	while (++i < len)
		if (a[i] >= pivot)
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

int			check_sorted(t_stack *stk)
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

// static void	filling_b_by_blocks(t_stack *stk, int *blocks, int *i)
// {
// 	int	pivot_a;
// 	int	start_alen;

	
// 	pivot_a = find_pivot(stk->a, stk->alen);
// 	start_alen = stk->alen;
// 	if (stk->alen > 3)
// 	{
// 		while (stk->alen != start_alen / 2)
// 			if (stk->a[0] >= pivot_a)
// 				ps_push_b(stk, 1);
// 			else
// 				ps_rotate(stk, "ra", 1);
// 		blocks[(*i)++] = start_alen - stk->alen;
// 	}
// 	if (stk->alen > 3)
// 		filling_b_by_blocks(stk, blocks, i);
// 	else
// 	{
// 		sort_first_top_a(stk);
// 		(*i)--;
// 	}
// }

static void	filling_b_by_blocks(t_stack *stk, int *blocks, int *i)
{
	int	pivot_a;
	int	upper_pivot;
	int	start_alen;

	
	pivot_a = find_pivot(stk->a, stk->alen);
	upper_pivot = find_upper_pivot(stk, stk->a, pivot_a, stk->alen);
	start_alen = stk->alen;
	if (stk->alen > 3)
	{
		while (stk->alen != start_alen / 2)
			if (stk->a[0] >= pivot_a)
				ps_push_b(stk, 1);
			else if (stk->b[0] >= upper_pivot && stk->blen > 1 && *i == 0)
				ps_rotate(stk, "rr", 1);
			else
				ps_rotate(stk, "ra", 1);
		blocks[(*i)++] = start_alen - stk->alen;
	}
	if (stk->alen > 3)
		filling_b_by_blocks(stk, blocks, i);
	else
	{
		sort_first_top_a(stk);
		(*i)--;
	}
}

static void	sort_stack(t_stack *stk)
{
	int	*blocks;
	int	i;

	blocks = ft_memalloc(33);
	i = 0;
	if (check_sorted(stk) != stk->alen + stk->blen)
	{
		filling_b_by_blocks(stk, blocks, &i);
		while ((stk->sorted = check_sorted(stk)) != stk->alen + stk->blen && i >= 0)
		{
			sort_top_b_block(stk, blocks, &i);
			sort_pushed_to_a(stk, blocks, &i);
		}
	}
	// print_stack(stk);
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
		sort_stack(&stk);
	}
	else if (ac > 2)
	{
		stack_memory(&stk, ac - 1);
		validate_and_rec(&stk, ac, av);
		sort_stack(&stk);
	}
	// print_stack(&stk);
	// check_sort(&stk, stk.alen + stk.blen);
	free(stk.a);
	free(stk.b);
	return(0);
}
