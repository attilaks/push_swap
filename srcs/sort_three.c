/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:45:17 by jwillem-          #+#    #+#             */
/*   Updated: 2019/02/28 01:02:57 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	one_three_two(t_stack *stk)
{
	ps_push_b(stk, 1);
	ps_swap(stk, "sa", 1);
	ps_push_a(stk, 1);
}

static void	two_three_one(t_stack *stk)
{
	ps_push_b(stk, 1);
	ps_swap(stk, "sa", 1);
	ps_rotate(stk, "ra", 1);
	ps_push_a(stk, 1);
	ps_rev_rotate(stk, "rra", 1);
}

static void	three_one_two(t_stack *stk)
{
	ps_swap(stk, "sa", 1);
	ps_rotate(stk, "ra", 1);
	ps_swap(stk, "sa", 1);
	ps_rev_rotate(stk, "rra", 1);
}

static void	three_two_one(t_stack *stk)
{
	ps_push_b(stk, 1);
	ps_swap(stk, "sa", 1);
	ps_rotate(stk, "ra", 1);
	ps_rotate(stk, "ra", 1);
	ps_push_a(stk, 1);
	ps_rev_rotate(stk, "rra", 1);
	ps_rev_rotate(stk, "rra", 1);
}

void		sort_top_three_a(t_stack *stk)
{
	if (A(0) < A(1) && A(1) > A(2) && A(0) < A(2))
		one_three_two(stk);
	else if (A(0) > A(1) && A(1) < A(2) && A(0) < A(2))
		ps_swap(stk, "sa", 1);
	else if (A(0) < A(1) && A(1) > A(2) && A(0) > A(2))
		two_three_one(stk);
	else if (A(0) > A(1) && A(1) < A(2) && A(0) > A(2))
		three_one_two(stk);
	else if (A(0) > A(1) && A(1) > A(2) && A(0) > A(2))
		three_two_one(stk);
}
