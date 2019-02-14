/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:09:56 by jwillem-          #+#    #+#             */
/*   Updated: 2019/02/14 19:40:28 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char *av)
{
	t_stack	stk;

	stk.alen = 0;
	stk.blen = 0;
	if (!(stk.a = (int *)malloc(sizeof(int) * (ac - 1))) || \
		!(stk.b = (int *)malloc(sizeof(int) * (ac - 1))))
		put_error(&stk, "error");
	if (ac > 1)
	{
		validate_and_rec(&stk, ac, av);
	}
	print_stack(&stk);
	free(stk.a);
	free(stk.b);
	return(0);
}
