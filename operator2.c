/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:00:53 by djang             #+#    #+#             */
/*   Updated: 2024/06/08 16:00:55 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	t_node	*temp;

	if (a->currentcount < 2)
		return ;
	temp = deletefrontstack(a);
	insertrearstack(a, temp);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	t_node	*temp;

	if (b->currentcount < 2)
		return ;
	temp = deletefrontstack(b);
	insertrearstack(b, temp);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	t_node	*temp;
	t_node	*tempo;

	if (a->currentcount < 2)
		return ;
	if (b->currentcount < 2)
		return ;
	temp = deletefrontstack(a);
	insertrearstack(a, temp);
	tempo = deletefrontstack(b);
	insertrearstack(b, tempo);
	write(1, "rr\n", 3);
}
