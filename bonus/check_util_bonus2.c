/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_util_bonus2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:58:57 by djang             #+#    #+#             */
/*   Updated: 2024/06/14 19:58:58 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	samecheck(t_stack *a)
{
	t_node	*i;
	t_node	*j;
	int		temp;

	i = a->rear;
	while (i)
	{
		temp = i->num;
		j = i->prev;
		while (j)
		{
			if (temp == j->num)
			{
				destroystack(a);
				error();
			}
			j = j->prev;
		}
		i = i->prev;
	}
}

void	sortedcheck(t_stack *a, t_stack *b)
{
	t_node	*now;

	now = a->rear;
	while (now->prev)
	{
		if (now->num > now->prev->num)
			now = now->prev;
		else
		{
			write(1, "KO\n", 3);
			return ;
		}
	}
	if (b->currentcount == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return ;
}
