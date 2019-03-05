/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:47:27 by jwillem-          #+#    #+#             */
/*   Updated: 2019/03/05 16:47:55 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		draw_back(t_stack *stk)
{
	int	h;
	int	w;

	h = -1;
	while (++h < W_HEIGHT)
	{
		w = -1;
		while (++w < W_WIDTH)
			stk->mlx.pic.data[h * W_WIDTH + w] = BACK;
	}
}

void		draw_a(t_stack *stk)
{
	t_draw	draw;

	draw.h = W_HEIGHT;
	draw.i = stk->alen - 1;
	draw.drawing = 1;
	while (--draw.h >= W_HEIGHT - INT_H * stk->alen && draw.i >= 0)
	{
		draw.w = -1;
		while (++draw.w < W_WIDTH / 2)
			if ((draw.w >= W_WIDTH / 4 - INT_W * ABS(A(draw.i)) / 2) && \
				(draw.w <= W_WIDTH / 4 + INT_W * ABS(A(draw.i)) / 2))
			{
				if (stk->a[draw.i] < 0)
					stk->mlx.pic.data[draw.h * W_WIDTH + draw.w] = NEGATIVE;
				else
					stk->mlx.pic.data[draw.h * W_WIDTH + draw.w] = POSITIVE;
			}
			else if ((draw.w > W_WIDTH / 4 + INT_W * ABS(A(draw.i)) / 2) \
				&& (draw.h == W_HEIGHT - INT_H * draw.drawing))
			{
				draw.drawing++;
				draw.i--;
				break ;
			}
	}
}

void		draw_b(t_stack *stk)
{
	t_draw	draw;

	draw.h = W_HEIGHT;
	draw.i = stk->blen - 1;
	draw.drawing = 1;
	while (--draw.h >= W_HEIGHT - INT_H * stk->blen && draw.i >= 0)
	{
		draw.w = -1;
		while (++draw.w < W_WIDTH)
			if ((draw.w >= W_WIDTH * 3 / 4 - INT_W * ABS(B(draw.i)) / 2) && \
				(draw.w <= W_WIDTH * 3 / 4 + INT_W * ABS(B(draw.i)) / 2))
			{
				if (stk->b[draw.i] < 0)
					stk->mlx.pic.data[draw.h * W_WIDTH + draw.w] = NEGATIVE;
				else
					stk->mlx.pic.data[draw.h * W_WIDTH + draw.w] = POSITIVE;
			}
			else if ((draw.w > W_WIDTH * 3 / 4 + INT_W * ABS(B(draw.i)) / 2) \
				&& (draw.h == W_HEIGHT - INT_H * draw.drawing))
			{
				draw.drawing++;
				draw.i--;
				break ;
			}
	}
}
