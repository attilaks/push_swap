/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:17:21 by jwillem-          #+#    #+#             */
/*   Updated: 2019/03/07 23:48:35 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ps_swap(t_stack *stk, char *line, int print)
{
	if (!ft_strcmp(line, "sa"))
	{
		if (stk->alen > 1)
			ft_swap(&stk->a[0], &stk->a[1]);
	}
	else if (!ft_strcmp(line, "sb"))
	{
		if (stk->blen > 1)
			ft_swap(&stk->b[0], &stk->b[1]);
	}
	else if (!ft_strcmp(line, "ss"))
	{
		ps_swap(stk, "sa", 0);
		ps_swap(stk, "sb", 0);
	}
	if (print)
		ft_printf("%s\n", line);
}

void	ps_push_a(t_stack *stk, int print)
{
	int	i;

	if (stk->blen == 0)
		return ;
	i = ++stk->alen;
	while (--i > 0)
		stk->a[i] = stk->a[i - 1];
	stk->a[0] = stk->b[0];
	--stk->blen;
	i = -1;
	while (++i < stk->blen)
		stk->b[i] = stk->b[i + 1];
	if (print)
		ft_printf("pa\n");
}

void	ps_push_b(t_stack *stk, int print)
{
	int	i;

	if (stk->alen == 0)
		return ;
	i = ++stk->blen;
	while (--i > 0)
		stk->b[i] = stk->b[i - 1];
	stk->b[0] = stk->a[0];
	--stk->alen;
	i = -1;
	while (++i < stk->alen)
		stk->a[i] = stk->a[i + 1];
	if (print)
		ft_printf("pb\n");
}

void	ps_rotate(t_stack *stk, char *line, int print)
{
	int	i;
	int	tmp;

	i = 0;
	if (!ft_strcmp(line, "ra"))
	{
		tmp = stk->a[0];
		while (++i < stk->alen)
			stk->a[i - 1] = stk->a[i];
		stk->a[i - 1] = tmp;
	}
	else if (!ft_strcmp(line, "rb"))
	{
		tmp = stk->b[0];
		while (++i < stk->blen)
			stk->b[i - 1] = stk->b[i];
		stk->b[i - 1] = tmp;
	}
	else if (!ft_strcmp(line, "rr"))
	{
		ps_rotate(stk, "ra", 0);
		ps_rotate(stk, "rb", 0);
	}
	if (print)
		ft_printf("%s\n", line);
}

void	ps_rev_rotate(t_stack *stk, char *line, int print)
{
	int	len;
	int	tmp;

	len = (!ft_strcmp(line, "rra") ? stk->alen : stk->blen);
	if (!ft_strcmp(line, "rra"))
	{
		tmp = stk->a[len - 1];
		while (--len > 0)
			stk->a[len] = stk->a[len - 1];
		stk->a[len] = tmp;
	}
	else if (!ft_strcmp(line, "rrb"))
	{
		tmp = stk->b[len - 1];
		while (--len > 0)
			stk->b[len] = stk->b[len - 1];
		stk->b[len] = tmp;
	}
	else if (!ft_strcmp(line, "rrr"))
	{
		ps_rev_rotate(stk, "rra", 0);
		ps_rev_rotate(stk, "rrb", 0);
	}
	if (print)
		ft_printf("%s\n", line);
}
