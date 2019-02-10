/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:31:14 by jwillem-          #+#    #+#             */
/*   Updated: 2019/02/10 15:12:04 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "ft_printf.h"

typedef struct	s_stack	
{
	int	*aarr;
	int	*barr;
}				t_stack;

void	put_error(t_stack *stacks);
void	validate_and_rec(t_stack *stacks, int ac, char **av);
// void	create_stacks(t_stack *stacks, int ac);
void	check_sort(t_stack *stacks);

#endif
