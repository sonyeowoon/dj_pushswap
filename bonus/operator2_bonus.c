/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:03:23 by djang             #+#    #+#             */
/*   Updated: 2024/06/18 18:50:45 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_stack *a)
{
	t_node	*temp;

	if (a->currentcount < 2)
		return ;
	temp = deletefrontstack(a);
	insertrearstack(a, temp);
}

void	rb(t_stack *b)
{
	t_node	*temp;

	if (b->currentcount < 2)
		return ;
	temp = deletefrontstack(b);
	insertrearstack(b, temp);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
