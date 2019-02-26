/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:17:21 by jwillem-          #+#    #+#             */
/*   Updated: 2019/02/26 06:44:47 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ps_swap(t_stack *stacks, char *line, int print)
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
		ps_swap(stacks, "sa", 0);
		ps_swap(stacks, "sb", 0);
	}
	if (print)
		ft_printf("%s\n", line);
	// print_stack(stacks);
}

void	ps_push_a(t_stack *stacks, int print)
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
	if (print)
		ft_printf("pa\n");
	// print_stack(stacks);
}

void	ps_push_b(t_stack *stacks, int print)
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
	if (print)
		ft_printf("pb\n");
	// print_stack(stacks);
}

void	ps_rotate(t_stack *stacks, char *line, int print)
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
		ps_rotate(stacks, "ra", 0);
		ps_rotate(stacks, "rb", 0);
	}
	if (print)
		ft_printf("%s\n", line);
	// print_stack(stacks);
}

void	ps_rev_rotate(t_stack *stacks, char *line, int print)
{
	int	len;
	int	tmp;

	len = (!ft_strcmp(line, "rra") ? stacks->alen : stacks->blen);
	if (!ft_strcmp(line, "rra"))
	{
		tmp = stacks->a[len - 1];
		while (--len > 0)
			stacks->a[len] = stacks->a[len - 1];
		stacks->a[len] = tmp;
	}
	else if (!ft_strcmp(line, "rrb"))
	{
		tmp = stacks->b[len - 1];
		while (--len > 0)
			stacks->b[len] = stacks->b[len - 1];
		stacks->b[len] = tmp;
	}
	else if (!ft_strcmp(line, "rrr"))
	{
		ps_rev_rotate(stacks, "rra", 0);
		ps_rev_rotate(stacks, "rrb", 0);
	}
	if (print)
		ft_printf("%s\n", line);
	// print_stack(stacks);
}
