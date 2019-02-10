/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:17:21 by jwillem-          #+#    #+#             */
/*   Updated: 2019/02/10 22:00:13 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		if (stacks->alen > 1 && stacks->blen > 1)
		{
			ft_swap(&stacks->aarr[0], &stacks->aarr[1]);
			ft_swap(&stacks->barr[0], &stacks->barr[1]);
		}
	}
}

void	ps_push(t_stack *stacks, char *line)
{
	int	i;
	
	i = 0;
	if (!ft_strcmp(line, "pa"))
	{
		if (stacks->blen > 0)
		{
			stacks->blen--;
			stacks->alen++;
			while (i < stacks->alen)
			{
				stacks->aarr[stacks->alen - 1] = 
			}
		}
	}
}
