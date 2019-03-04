/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:31:14 by jwillem-          #+#    #+#             */
/*   Updated: 2019/03/04 21:49:18 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "ft_printf.h"
# include "mlx.h"

# define A(i)	stk->a[i]
# define B(i)	stk->b[i]

# define W_WIDTH	800
# define W_HEIGHT	600

typedef struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win;
	t_img	pic;
	int		int_height;
	int		int_width;
}				t_mlx;

typedef struct	s_stack
{
	int		*a;
	int		*b;
	int		alen;
	int		blen;
	int		sorted;
	t_mlx	mlx;
}				t_stack;

/*
**	Common functions
*/

void			put_error(char *error);
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
**	Checker
*/

void			do_operation(t_stack *stacks, char *line);
void			check_sort(t_stack *stacks, int num_quant);

/*
**	Push_swap
*/

int				find_pivot(int *a, int len);
int				find_low_pivot(int *a, int pivot, int len);
int				check_sorted(t_stack *stk);
void			sort_top_b_block(t_stack *stk, int *blocks, int *i);
void			sort_pushed_to_a(t_stack *stk, int *blocks, int *i);
void			sort_first_top_a(t_stack *stk);
void			sort_top_three_a(t_stack *stk);

/*
**	Visual presentation
*/

void			visualization(t_stack *stk);
void			draw_back(t_stack *stk);
// int				max_abs(t_stack *stk);
void			draw_a(t_stack *stk);
void			draw_b(t_stack *stk);
// int				visual_hook(t_stack *stk);
// int				close_win(t_stack *stk);

#endif
