/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:17:21 by jwillem-          #+#    #+#             */
/*   Updated: 2019/02/12 22:00:57 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ps_swap(t_stack *stacks, char *line)
{
	if (!ft_strcmp(line, "sa"))
	{
		if (stacks->alen > 1)
			ft_swap(&stacks->aarr[0], &stacks->aarr[1]);
	}
	else if (!ft_strcmp(line, "sb"))
	{
		if (stacks->blen > 1)
			ft_swap(&stacks->barr[0], &stacks->barr[1]);
	}
	else if (!ft_strcmp(line, "ss"))
	{
		ps_swap(stacks, "sa");
		ps_swap(stacks, "sb");
	}
}

// void	ps_push(t_stack *stacks, char *line)
// {
// 	if (!ft_strcmp(line, "pa"))
// 	{
// 		if (stacks->blen-- > 0 && ++stacks->alen)
// 			ft_swap(&stacks->aarr[stacks->alen - 1], \
// 			&stacks->barr[stacks->blen]);
// 	}
// 	else if (!ft_strcmp(line, "pb"))
// 	{
// 		if (stacks->alen-- > 0 && ++stacks->blen)
// 			ft_swap(&stacks->aarr[stacks->alen], \
// 			&stacks->barr[stacks->blen - 1]);
// 			// ft_swap(&stacks->aarr[0], &stacks->barr[-1]);
// 	}
// }

void	ps_push_b(t_stack *stacks)
{
	int	atmp[stacks->alen - 1];
	int	btmp[stacks->blen + 1];
	int	i;

	i = 0;
	if (stacks->alen == 0)
		return ;
	btmp[0] = stacks->aarr[0];
}

void	ps_rotate(t_stack *stacks, char *line)
{
	int	i;
	int	tmp;

	i = 0;
	if (!ft_strcmp(line, "ra"))
	{
		tmp = stacks->aarr[0];
		while (++i < stacks->alen)
			stacks->aarr[i - 1] = stacks->aarr[i];
		stacks->aarr[i - 1] = tmp;
	}
	else if (!ft_strcmp(line, "rb"))
	{
		tmp = stacks->barr[0];
		while (++i < stacks->blen)
			stacks->barr[i - 1] = stacks->barr[i];
		stacks->barr[i - 1] = tmp;
	}
	else if (!ft_strcmp(line, "rr"))
	{
		ps_rev_rotate(stacks, "ra");
		ps_rev_rotate(stacks, "rb");
	}
}

void	ps_rev_rotate(t_stack *stacks, char *line)
{
	int	a;
	int	b;
	int	tmp;

	a = stacks->alen;
	b = stacks->blen;	
	if (!ft_strcmp(line, "rra"))
	{
		tmp = stacks->aarr[a - 1];
		while (--a > 0)
			stacks->aarr[a] = stacks->aarr[a - 1];
		stacks->aarr[a] = tmp;
	}
	else if (!ft_strcmp(line, "rrb"))
	{
		tmp = stacks->barr[b - 1];
		while (--b > 0)
			stacks->barr[b] = stacks->barr[b - 1];
		stacks->barr[b] = tmp;
	}
	else if (!ft_strcmp(line, "rrr"))
	{
		ps_rotate(stacks, "rra");
		ps_rotate(stacks, "rrb");
	}
}
