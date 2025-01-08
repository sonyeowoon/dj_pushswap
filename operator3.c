/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:00:59 by djang             #+#    #+#             */
/*   Updated: 2024/06/08 16:01:02 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	t_node	*temp;

	if (a->currentcount < 2)
		return ;
	temp = deleterearstack(a);
	insertfrontstack(a, temp);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	t_node	*temp;

	if (b->currentcount < 2)
		return ;
	temp = deleterearstack(b);
	insertfrontstack(b, temp);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	t_node	*temp;
	t_node	*tempo;

	if (a->currentcount < 2)
		return ;
	if (b->currentcount < 2)
		return ;
	temp = deleterearstack(a);
	insertfrontstack(a, temp);
	tempo = deleterearstack(b);
	insertfrontstack(b, tempo);
	write(1, "rrr\n", 4);
}
