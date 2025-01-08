/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:00:45 by djang             #+#    #+#             */
/*   Updated: 2024/06/08 16:00:47 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->currentcount < 2)
		return ;
	temp = a -> front -> num;
	a -> front -> num = a -> front ->next -> num;
	a -> front ->next -> num = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	temp;

	if (b->currentcount < 2)
		return ;
	temp = b -> front -> num;
	b -> front -> num = b -> front ->next -> num;
	b -> front ->next -> num = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	int	temp;
	int	tempo;

	if (a->currentcount < 2)
		return ;
	if (b->currentcount < 2)
		return ;
	temp = a -> front -> num;
	a -> front -> num = a -> front ->next -> num;
	a -> front ->next -> num = temp;
	tempo = b -> front -> num;
	b -> front -> num = b -> front ->next -> num;
	b -> front ->next -> num = tempo;
	write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (b->currentcount == 0)
		return ;
	temp = deletefrontstack(b);
	insertfrontstack(a, temp);
	write(1, "pa\n", 3);
}

void	pb(t_stack *b, t_stack *a)
{
	t_node	*temp;

	if (a->currentcount == 0)
		return ;
	temp = deletefrontstack(a);
	insertfrontstack(b, temp);
	write(1, "pb\n", 3);
}
