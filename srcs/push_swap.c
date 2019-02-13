/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:09:56 by jwillem-          #+#    #+#             */
/*   Updated: 2019/02/13 20:23:05 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char *av)
{
	t_stack	stacks;

	stacks.alen = 0;
	stacks.blen = 0;
	if (!(stacks.aarr = (int *)malloc(sizeof(int) * (ac - 1))) || \
		!(stacks.barr = (int *)malloc(sizeof(int) * (ac - 1))))
		put_error(&stacks, "error");
	if (ac > 1)
	{
		validate_and_rec(&stacks, ac, av);

	}
}
