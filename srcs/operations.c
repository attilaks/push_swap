/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:17:21 by jwillem-          #+#    #+#             */
/*   Updated: 2019/02/11 22:03:03 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_stack(t_stack *stacks)
{

}

void	get_sort_instructions(t_stack *stacks)
{
	char	*line;

	while (get_next_line(0, &line) == 1)
	{
		if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "sb") || \
			!ft_strcmp(line, "ss"))
			ps_swap(stacks, line);
		else if (!ft_strcmp(line, "pa") || !ft_strcmp(line, "pb"))
			ps_push(stacks, line);
		else if (!ft_strcmp(line, "ra") || !ft_strcmp(line, "rb") || \
			!ft_strcmp(line, "rr"))
			ps_rotate(stacks, line);
		else if (!ft_strcmp(line, "rra") || !ft_strcmp(line, "rrb") || \
			!ft_strcmp(line, "rrr"))
			ps_rev_rotate(stacks, line);
		else
			put_error(stacks, "error");	
	}
	print_stack(stacks);
}

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

void	ps_push(t_stack *stacks, char *line)
{
	if (!ft_strcmp(line, "pa"))
		if (stacks->blen-- > 0 && stacks->alen++)
			ft_swap(&stacks->aarr[stacks->alen - 1], \
			&stacks->barr[stacks->blen]);
	else if (!ft_strcmp(line, "pb"))
		if (stacks->alen-- > 0 && stacks->blen++)
			ft_swap(&stacks->aarr[stacks->alen], \
			&stacks->barr[stacks->blen - 1]);
}

void	ps_rotate(t_stack *stacks, char *line)
{
	int	a;
	int	b;
	int	tmp;

	a = stacks->alen;
	b = stacks->blen;	
	if (!ft_strcmp(line, "ra"))
	{
		tmp = stacks->aarr[a - 1];
		while (--a > 0)
			stacks->aarr[a] = stacks->aarr[a - 1];
		stacks->aarr[a] = tmp;
	}
	else if (!ft_strcmp(line, "rb"))
	{
		tmp = stacks->barr[b - 1];
		while (--b > 0)
			stacks->barr[b] = stacks->barr[b - 1];
		stacks->barr[b] = tmp;
	}
	else if (!ft_strcmp(line, "rr"))
	{
		ps_rotate(stacks, "ra");
		ps_rotate(stacks, "rb");
	}
}

void	ps_rev_rotate(t_stack *stacks, char *line)
{
	int	i;
	int	tmp;

	i = 0;
	if (!ft_strcmp(line, "rra"))
	{
		tmp = stacks->aarr[0];
		while (++i < stacks->alen)
			stacks->aarr[i - 1] = stacks->aarr[i];
		stacks->aarr[i - 1] = tmp;
	}
	else if (!ft_strcmp(line, "rrb"))
	{
		tmp = stacks->barr[0];
		while (++i < stacks->blen)
			stacks->barr[i - 1] = stacks->barr[i];
		stacks->barr[i - 1] = tmp;
	}
	else if (!ft_strcmp(line, "rrr"))
	{
		ps_rev_rotate(stacks, "rra");
		ps_rev_rotate(stacks, "rrb");
	}
}
