/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:31:14 by jwillem-          #+#    #+#             */
/*   Updated: 2019/02/26 07:01:38 by jwillem-         ###   ########.fr       */
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
	int	sorted;
}				t_stack;

/*
**	Common functions
*/

void			put_error(t_stack *stk, char *error);
void			validate_and_rec(t_stack *stk, int ac, char **av);
void			validate_and_rec_split(t_stack *stk, int numbers, char **split);
int				split_len(char **split);
void			stack_memory(t_stack *stk, int memory);

/*
**	Operations
*/

void			ps_swap(t_stack *stacks, char *line, int print);
void			ps_push_a(t_stack *stacks, int print);
void			ps_push_b(t_stack *stacks, int print);
void			ps_rotate(t_stack *stacks, char *line, int print);
void			ps_rev_rotate(t_stack *stacks, char *line, int print);

void			print_stack(t_stack *stacks);

/*
**	Push_swap
*/

int				find_pivot(int *a, int len);
int				find_upper_pivot(t_stack *stk, int *a, int pivot, int len);
int				check_sorted(t_stack *stk);
void			sort_top_b_block(t_stack *stk, int *blocks, int *i);
void			sort_pushed_to_a(t_stack *stk, int *blocks, int *i);
void			sort_first_top_a(t_stack *stk);
// void			sort_top_three_a(t_stack *stk, int *blocks, int *i);

#endif
