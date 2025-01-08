/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:03:15 by djang             #+#    #+#             */
/*   Updated: 2024/06/14 17:03:18 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->currentcount < 2)
		return ;
	temp = a -> front -> num;
	a -> front -> num = a -> front ->next -> num;
	a -> front ->next -> num = temp;
}

void	sb(t_stack *b)
{
	int	temp;

	if (b->currentcount < 2)
		return ;
	temp = b -> front -> num;
	b -> front -> num = b -> front ->next -> num;
	b -> front ->next -> num = temp;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (b->currentcount == 0)
		return ;
	temp = deletefrontstack(b);
	insertfrontstack(a, temp);
}

void	pb(t_stack *b, t_stack *a)
{
	t_node	*temp;

	if (a->currentcount == 0)
		return ;
	temp = deletefrontstack(a);
	insertfrontstack(b, temp);
}
