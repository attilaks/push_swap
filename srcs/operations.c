/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:17:21 by jwillem-          #+#    #+#             */
/*   Updated: 2019/02/14 20:33:09 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ps_swap(t_stack *stacks, char *line)
{
	if (!ft_strcmp(line, "sa"))
	{
		if (stacks->alen > 1)
			ft_swap(&stacks->a[0], &stacks->a[1]);
	}
	else if (!ft_strcmp(line, "sb"))
	{
		if (stacks->blen > 1)
			ft_swap(&stacks->b[0], &stacks->b[1]);
	}
	else if (!ft_strcmp(line, "ss"))
	{
		ps_swap(stacks, "sa");
		ps_swap(stacks, "sb");
	}
}

void	ps_push_a(t_stack *stacks)
{
	int	i;

	if (stacks->blen == 0)
		return ;
	i = ++stacks->alen;
	while (--i > 0)
		stacks->a[i] = stacks->a[i - 1];
	stacks->a[0] = stacks->b[0];
	--stacks->blen;
	i = -1;
	while (++i < stacks->blen)
		stacks->b[i] = stacks->b[i + 1];
}

void	ps_push_b(t_stack *stacks)
{
	int	i;

	if (stacks->alen == 0)
		return ;
	i = ++stacks->blen;
	while (--i > 0)
		stacks->b[i] = stacks->b[i - 1];
	stacks->b[0] = stacks->a[0];
	--stacks->alen;
	i = -1;
	while (++i < stacks->alen)
		stacks->a[i] = stacks->a[i + 1];
}

void	ps_rotate(t_stack *stacks, char *line)
{
	int	i;
	int	tmp;

	i = 0;
	if (!ft_strcmp(line, "ra"))
	{
		tmp = stacks->a[0];
		while (++i < stacks->alen)
			stacks->a[i - 1] = stacks->a[i];
		stacks->a[i - 1] = tmp;
	}
	else if (!ft_strcmp(line, "rb"))
	{
		tmp = stacks->b[0];
		while (++i < stacks->blen)
			stacks->b[i - 1] = stacks->b[i];
		stacks->b[i - 1] = tmp;
	}
	else if (!ft_strcmp(line, "rr"))
	{
		ps_rotate(stacks, "ra");
		ps_rotate(stacks, "rb");
	}
}

void	ps_rev_rotate(t_stack *stacks, char *line)
{
	int	al;
	int	bl;
	int	tmp;

	al = stacks->alen;
	bl = stacks->blen;
	if (!ft_strcmp(line, "rra"))
	{
		tmp = stacks->a[al - 1];
		while (--al > 0)
			stacks->a[al] = stacks->a[al - 1];
		stacks->a[al] = tmp;
	}
	else if (!ft_strcmp(line, "rrb"))
	{
		tmp = stacks->b[bl - 1];
		while (--bl > 0)
			stacks->b[bl] = stacks->b[bl - 1];
		stacks->b[bl] = tmp;
	}
	else if (!ft_strcmp(line, "rrr"))
	{
		ps_rev_rotate(stacks, "rra");
		ps_rev_rotate(stacks, "rrb");
	}
}
