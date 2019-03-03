/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 04:43:01 by jwillem-          #+#    #+#             */
/*   Updated: 2019/03/03 08:01:12 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			max_abs(t_stack *stk)
{
	int	i;
	int	max;

	i = 0;
	max = stk->a[i];
	while (stk->a[++i])
	{
		if (ABS(stk->a[i]) > max)
			max = ABS(stk->a[i]);
	}
	return (max);
}

void		draw_back(t_stack *stk)
{
	int	h;
	int	w;

	h = -1;
	while (++h < W_HEIGHT)
	{
		w = -1;
		while (++w < W_WIDTH)
			stk->mlx.back.data[h * W_WIDTH + w] = 0xFFFF00;
	}
	mlx_put_image_to_window(stk->mlx.mlx_ptr, stk->mlx.win, stk->mlx.back.img_ptr, 0, 0);
}

// void		draw_back(t_mlx *mlx)
// {
// 	int	h;
// 	int	w;

// 	h = -1;
// 	while (++h < W_HEIGHT)
// 	{
// 		w = -1;
// 		while (++w < W_WIDTH)
// 			mlx_pixel_put(mlx->mlx_ptr, mlx->win, w, h, 0xFFFF00);
// 	}
// }

// void		draw_a(t_stack *stk, t_mlx *mlx)
// {
// 	int	h;
// 	int	w;
// 	int	i;
// 	int	drawing;

// 	h = W_HEIGHT;
// 	i = stk->alen;
// 	drawing = 1;
// 	while(--h >= 0 && i >= 0)
// 	{
// 		w = -1;
// 		if (h < W_HEIGHT - mlx->int_height * drawing)
// 			i--;
// 		while (++w < W_WIDTH / 2)
// 			if ((w >= W_WIDTH / 4 - mlx->int_width * ABS(stk->a[i]) / 2) && \
// 				(w <= W_WIDTH / 4 + mlx->int_width * ABS(stk->a[i]) / 2))
// 			{
// 				if (stk->a[i] < 0)	
// 					mlx->a.data[h * W_WIDTH + w] = 0x0000FF;
// 				else
// 					mlx->a.data[h * W_WIDTH + w] = 0xFF0000;
// 			}
// 			else if ((w > W_WIDTH / 4 + mlx->int_width * ABS(stk->a[i]) / 2) \
// 				&& (h == W_HEIGHT - mlx->int_height * drawing))
// 			{
// 				drawing++;
// 				break ;
// 			}
// 	}
// 	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->a.img_ptr, 0, 0);
// }

void		draw_a(t_stack *stk)
{
	int	h;
	int	w;
	int	i;
	int	drawing;

	h = W_HEIGHT;
	i = stk->alen;
	drawing = 1;
	while(--h >= W_HEIGHT - stk->mlx.int_height * stk->alen && i >= 0)
	{
		w = -1;
		if (h < W_HEIGHT - stk->mlx.int_height * drawing)
			i--;
		while (++w < W_WIDTH / 2)
			if ((w >= W_WIDTH / 4 - stk->mlx.int_width * ABS(stk->a[i]) / 2) && \
				(w <= W_WIDTH / 4 + stk->mlx.int_width * ABS(stk->a[i]) / 2) && stk->a[i])
			{
				if (stk->a[i] < 0)	
					stk->mlx.a.data[h * W_WIDTH + w] = 0x0000FF;
				else
					stk->mlx.a.data[h * W_WIDTH + w] = 0xFF0000;
			}
			else if ((w > W_WIDTH / 4 + stk->mlx.int_width * ABS(stk->a[i]) / 2) \
				&& (h == W_HEIGHT - stk->mlx.int_height * drawing))
			{
				drawing++;
				break ;
			}
	}
	mlx_put_image_to_window(stk->mlx.mlx_ptr, stk->mlx.win, stk->mlx.a.img_ptr, 0, 0);
}

// void		draw_b(t_stack *stk, t_mlx *mlx)
// {
// 	int	h;
// 	int	w;
// 	int	i;
// 	int	drawing;

// 	h = W_HEIGHT;
// 	i = stk->blen;
// 	drawing = 1;
// 	while(--h >= 0)
// 	{
// 		w = -1;
// 		if (h < W_HEIGHT - mlx->int_height * drawing)
// 			i--;
// 		while (++w < W_WIDTH / 2)
// 			if ((w >= W_WIDTH / 4 - mlx->int_width * ABS(stk->b[i]) / 2) && \
// 				(w <= W_WIDTH / 4 + mlx->int_width * ABS(stk->b[i]) / 2))
// 			{
// 				if (stk->b[i] < 0)	
// 					mlx->b.data[h * W_WIDTH + w] = 0x000000;
// 				else
// 					mlx->b.data[h * W_WIDTH + w] = 0xFFFFFF;
// 			}
// 			else if ((w > W_WIDTH / 4 + mlx->int_width * ABS(stk->b[i]) / 2) \
// 				&& (h == W_HEIGHT - mlx->int_height * drawing))
// 			{
// 				drawing++;
// 				break ;
// 			}
// 	}
// 	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->b.img_ptr, W_WIDTH / 2, 0);
// }

void		draw_b(t_stack *stk)
{
	int	h;
	int	w;
	int	i;
	int	drawing;

	h = W_HEIGHT;
	i = stk->blen;
	drawing = 1;
	while(--h >= W_HEIGHT - stk->mlx.int_height * stk->alen)
	{
		w = -1;
		if (h < W_HEIGHT - stk->mlx.int_height * drawing)
			i--;
		while (++w < W_WIDTH / 2)
			if ((w >= W_WIDTH / 4 - stk->mlx.int_width * ABS(stk->b[i]) / 2) && \
				(w <= W_WIDTH / 4 + stk->mlx.int_width * ABS(stk->b[i]) / 2) && stk->b[i])
			{
				if (stk->b[i] < 0)	
					stk->mlx.b.data[h * W_WIDTH + w] = 0x0000FF;
				else
					stk->mlx.b.data[h * W_WIDTH + w] = 0xFF0000;
			}
			else if ((w > W_WIDTH / 4 + stk->mlx.int_width * ABS(stk->b[i]) / 2) \
				&& (h == W_HEIGHT - stk->mlx.int_height * drawing))
			{
				drawing++;
				break ;
			}
	}
	mlx_put_image_to_window(stk->mlx.mlx_ptr, stk->mlx.win, \
		stk->mlx.b.img_ptr, W_WIDTH / 2, 0);
}

int			visual_hook(t_stack *stk)
{
	static char	finish;
	char		*line;

	if (finish)
		return (1);
	if (get_next_line(0, &line) == 1)
	{
		do_operation(stk, line);
		ft_bzero(stk->mlx.a.data, W_HEIGHT * W_WIDTH / 2);
		ft_bzero(stk->mlx.b.data, W_HEIGHT * W_WIDTH / 2);
		draw_back(stk);
		draw_a(stk);
		draw_b(stk);
		return (1);
	}
	check_sort(stk, stk->alen + stk->blen);
	finish = 1;
	return (1);
}

// void		visualization(t_stack *stk)
// {
// 	t_mlx	mlx;
// 	// char	*line;

// 	mlx.mlx_ptr = mlx_init();
// 	mlx.win = mlx_new_window(mlx.mlx_ptr, W_WIDTH, W_HEIGHT, \
// 		"Let the sorting begin!");
// 	mlx.back.img_ptr = mlx_new_image(mlx.mlx_ptr, W_WIDTH, W_HEIGHT);
// 	mlx.back.data = (int *)mlx_get_data_addr(mlx.back.img_ptr, &mlx.back.bpp, \
// 		&mlx.back.size_l, &mlx.back.endian);
// 	// mlx.back.bpp /= 4;
// 	mlx.a.img_ptr = mlx_new_image(mlx.mlx_ptr, W_WIDTH, W_HEIGHT);
// 	mlx.a.data = (int *)mlx_get_data_addr(mlx.a.img_ptr, &mlx.a.bpp, \
// 		&mlx.a.size_l, &mlx.a.endian);
// 	// mlx.a.bpp /= 4;
// 	mlx.b.img_ptr = mlx_new_image(mlx.mlx_ptr, W_WIDTH, W_HEIGHT);
// 	mlx.b.data = (int *)mlx_get_data_addr(mlx.b.img_ptr, &mlx.b.bpp, \
// 		&mlx.b.size_l, &mlx.b.endian);
// 	// mlx.b.bpp /= 4;
// 	mlx.int_height = W_HEIGHT / stk->alen;
// 	mlx.int_width = W_WIDTH / 2 / max_abs(stk);
// 	draw_back(&mlx);
// 	draw_a(stk, &mlx);
// 	// if (get_next_line(0, &line) == 1)
// 	// {
// 	// 	do_operation(stk, line);
// 	// 	ft_bzero(mlx.a.data, W_HEIGHT * W_WIDTH / 2);
// 	// 	ft_bzero(mlx.b.data, W_HEIGHT * W_WIDTH / 2);
// 	// 	draw_a(stk, &mlx);
// 	// 	draw_b(stk, &mlx);
// 	// }
// 	mlx_loop_hook(mlx.mlx_ptr, visual_hook, stk);
// 	mlx_loop(mlx.mlx_ptr);
// }

void		visualization(t_stack *stk)
{
	// t_mlx	mlx;
	// char	*line;

	stk->mlx.mlx_ptr = mlx_init();
	stk->mlx.win = mlx_new_window(stk->mlx.mlx_ptr, W_WIDTH, W_HEIGHT, \
		"Let the sorting begin!");
	stk->mlx.back.img_ptr = mlx_new_image(stk->mlx.mlx_ptr, W_WIDTH, W_HEIGHT);
	stk->mlx.back.data = (int *)mlx_get_data_addr(stk->mlx.back.img_ptr, \
		&stk->mlx.back.bpp, &stk->mlx.back.size_l, &stk->mlx.back.endian);
	// mlx.back.bpp /= 4;
	stk->mlx.a.img_ptr = mlx_new_image(stk->mlx.mlx_ptr, W_WIDTH, W_HEIGHT);
	stk->mlx.a.data = (int *)mlx_get_data_addr(stk->mlx.a.img_ptr, &stk->mlx.a.bpp, \
		&stk->mlx.a.size_l, &stk->mlx.a.endian);
	// mlx.a.bpp /= 4;
	stk->mlx.b.img_ptr = mlx_new_image(stk->mlx.mlx_ptr, W_WIDTH, W_HEIGHT);
	stk->mlx.b.data = (int *)mlx_get_data_addr(stk->mlx.b.img_ptr, &stk->mlx.b.bpp, \
		&stk->mlx.b.size_l, &stk->mlx.b.endian);
	// mlx.b.bpp /= 4;
	stk->mlx.int_height = W_HEIGHT / stk->alen;
	stk->mlx.int_width = W_WIDTH / 2 / max_abs(stk);
	draw_back(stk);
	draw_a(stk);
	draw_b(stk);
	// if (get_next_line(0, &line) == 1)
	// {
	// 	do_operation(stk, line);
	// 	ft_bzero(mlx.a.data, W_HEIGHT * W_WIDTH / 2);
	// 	ft_bzero(mlx.b.data, W_HEIGHT * W_WIDTH / 2);
	// 	draw_a(stk, &mlx);
	// 	draw_b(stk, &mlx);
	// }
	mlx_loop_hook(stk->mlx.mlx_ptr, visual_hook, stk);
	mlx_loop(stk->mlx.mlx_ptr);
}
