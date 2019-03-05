/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 04:43:01 by jwillem-          #+#    #+#             */
/*   Updated: 2019/03/05 16:48:32 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	max_abs(t_stack *stk)
{
	int	i;
	int	max;

	i = 0;
	max = ABS(stk->a[i]);
	while (stk->a[++i])
	{
		if (ABS(stk->a[i]) > max)
			max = ABS(stk->a[i]);
	}
	return (max);
}

static int	visual_hook(t_stack *stk)
{
	char		*line;

	draw_back(stk);
	draw_a(stk);
	draw_b(stk);
	if (get_next_line(0, &line) == 1)
		do_operation(stk, line);
	mlx_put_image_to_window(stk->mlx.mlx_ptr, stk->mlx.win, \
		stk->mlx.pic.img_ptr, 0, 0);
	return (1);
}

static int	close_win(t_stack *stk)
{
	check_sort(stk, stk->alen + stk->blen);
	exit(0);
}

void		visualization(t_stack *stk)
{
	stk->mlx.mlx_ptr = mlx_init();
	stk->mlx.win = mlx_new_window(stk->mlx.mlx_ptr, W_WIDTH, W_HEIGHT, \
		"Let the sorting begin!");
	stk->mlx.pic.img_ptr = mlx_new_image(stk->mlx.mlx_ptr, W_WIDTH, W_HEIGHT);
	stk->mlx.pic.data = (int *)mlx_get_data_addr(stk->mlx.pic.img_ptr, \
		&stk->mlx.pic.bpp, &stk->mlx.pic.size_l, &stk->mlx.pic.endian);
	stk->mlx.int_height = W_HEIGHT / stk->alen;
	stk->mlx.int_width = W_WIDTH / 2 / max_abs(stk) - 1;
	mlx_loop_hook(stk->mlx.mlx_ptr, visual_hook, stk);
	mlx_hook(stk->mlx.win, 17, 1L << 17, close_win, stk);
	mlx_loop(stk->mlx.mlx_ptr);
}
