/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:31:14 by jwillem-          #+#    #+#             */
/*   Updated: 2019/02/11 21:57:58 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "ft_printf.h"

typedef struct	s_stack	
{
	int	*aarr;
	int	*barr;
	int	alen;
	int	blen;
}				t_stack;

void	put_error(t_stack *stacks, char *error);
void	validate_and_rec(t_stack *stacks, int ac, char **av);
int		is_duplicate(int *aarr, int i);

void	get_sort_instructions(t_stack *stacks);
void	ps_swap(t_stack *stacks, char *line);
void	ps_push(t_stack *stacks, char *line);
void	ps_rotate(t_stack *stacks, char *line);
void	ps_rev_rotate(t_stack *stacks, char *line);

#endif
