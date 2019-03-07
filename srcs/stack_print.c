/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:13:31 by jwillem-          #+#    #+#             */
/*   Updated: 2019/03/07 23:46:33 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	printstackif_a_islonger(t_stack *stk, int lendif)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (lendif-- > 0)
		ft_printf("%-d\n", stk->a[i++]);
	while (i < stk->alen && j < stk->blen)
		ft_printf("%-11d\t%-d\n", stk->a[i++], stk->b[j++]);
}

static void	printstackif_b_islonger(t_stack *stk, int lendif)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (lendif++ < 0)
		ft_printf("           \t%-d\n", stk->b[j++]);
	while (i < stk->alen && j < stk->blen)
		ft_printf("%-11d\t%-d\n", stk->a[i++], stk->b[j++]);
}

void		print_stack(t_stack *stk)
{
	int	lendif;

	lendif = stk->alen - stk->blen;
	if (lendif >= 0)
		printstackif_a_islonger(stk, lendif);
	else
		printstackif_b_islonger(stk, lendif);
	ft_printf("-----------\t-----------\n");
	ft_printf("Stack A    \tStack B\n");
}
