/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator3_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:03:29 by djang             #+#    #+#             */
/*   Updated: 2024/06/18 18:50:55 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_stack *a)
{
	t_node	*temp;

	if (a->currentcount < 2)
		return ;
	temp = deleterearstack(a);
	insertfrontstack(a, temp);
}

void	rrb(t_stack *b)
{
	t_node	*temp;

	if (b->currentcount < 2)
		return ;
	temp = deleterearstack(b);
	insertfrontstack(b, temp);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
