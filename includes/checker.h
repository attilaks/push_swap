/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:31:14 by jwillem-          #+#    #+#             */
/*   Updated: 2019/02/19 18:33:20 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "ft_printf.h"

# define A(i)	stk->a[i]
# define B(i)	stk->b[i]

typedef struct	s_stack
{
	int	*a;
	int	*b;
	int	alen;
	int	blen;
}				t_stack;

void			put_error(t_stack *stacks, char *error);
void			validate_and_rec(t_stack *stacks, int ac, char **av);

void			ps_swap(t_stack *stacks, char *line, int print);
void			ps_push_a(t_stack *stacks, int print);
void			ps_push_b(t_stack *stacks, int print);
void			ps_rotate(t_stack *stacks, char *line, int print);
void			ps_rev_rotate(t_stack *stacks, char *line, int print);

void			print_stack(t_stack *stacks);

/*
**	Push_swap
*/

#endif
