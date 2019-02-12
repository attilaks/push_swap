/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:13:31 by jwillem-          #+#    #+#             */
/*   Updated: 2019/02/12 18:53:00 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	printstackif_a_islonger(t_stack *stacks, int lendif)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (lendif-- > 0)
		ft_printf("%-d\n", stacks->aarr[i++]);
	while (i < stacks->alen && j < stacks->blen)
		ft_printf("%-11d\t%-d\n", stacks->aarr[i++], stacks->barr[j++]);
}

static void	printstackif_b_islonger(t_stack *stacks, int lendif)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (lendif++ < 0)
		ft_printf("%-d\n", stacks->barr[j++]);
	while (i < stacks->alen && j < stacks->blen)
		ft_printf("%-11d\t%-d\n", stacks->aarr[i++], stacks->barr[j++]);
}

void		print_stack(t_stack *stacks)
{
	int	lendif;

	lendif = stacks->alen - stacks->blen;
	if (lendif >= 0)
		printstackif_a_islonger(stacks, lendif);
	else
		printstackif_b_islonger(stacks, lendif);
	ft_printf("-----------\t-----------\n");
	ft_printf("Stack A    \tStack B\n");
}
