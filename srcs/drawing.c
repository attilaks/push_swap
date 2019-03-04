/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:47:27 by jwillem-          #+#    #+#             */
/*   Updated: 2019/03/04 21:48:04 by jwillem-         ###   ########.fr       */
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
			stk->mlx.pic.data[h * W_WIDTH + w] = 0xFFFF00;
	}
}

void		draw_a(t_stack *stk)
{
	int	h;
	int	w;
	int	i;
	int	drawing;

	h = W_HEIGHT;
	i = stk->alen - 1;
	drawing = 1;
	while(--h >= W_HEIGHT - stk->mlx.int_height * stk->alen && i >= 0)
	{
		w = -1;
		while (++w < W_WIDTH / 2)
			if ((w >= W_WIDTH / 4 - stk->mlx.int_width * ABS(A(i)) / 2) && \
				(w <= W_WIDTH / 4 + stk->mlx.int_width * ABS(A(i)) / 2))
			{
				if (stk->a[i] < 0)	
					stk->mlx.pic.data[h * W_WIDTH + w] = 0x0000FF;
				else
					stk->mlx.pic.data[h * W_WIDTH + w] = 0xFF0000;
			}
			else if ((w > W_WIDTH / 4 + stk->mlx.int_width * ABS(A(i)) / 2) \
				&& (h == W_HEIGHT - stk->mlx.int_height * drawing))
			{
				drawing++;
				i--;
				break ;
			}
	}
}

void		draw_b(t_stack *stk)
{
	int	h;
	int	w;
	int	i;
	int	drawing;

	h = W_HEIGHT;
	i = stk->blen - 1;
	drawing = 1;
	while(--h >= W_HEIGHT - stk->mlx.int_height * stk->blen && i >= 0)
	{
		w = -1;
		while (++w < W_WIDTH)
			if ((w >= W_WIDTH - W_WIDTH / 4 - stk->mlx.int_width * ABS(B(i)) / 2) && \
				(w <= W_WIDTH - W_WIDTH / 4 + stk->mlx.int_width * ABS(B(i)) / 2))
			{
				if (stk->b[i] < 0)	
					stk->mlx.pic.data[h * W_WIDTH + w] = 0x0000FF;
				else
					stk->mlx.pic.data[h * W_WIDTH + w] = 0xFF0000;
			}
			else if ((w > W_WIDTH - W_WIDTH / 4 + stk->mlx.int_width * ABS(B(i)) / 2) \
				&& (h == W_HEIGHT - stk->mlx.int_height * drawing))
			{
				drawing++;
				i--;
				break ;
			}
	}
}
