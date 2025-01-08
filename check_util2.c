/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:49:41 by djang             #+#    #+#             */
/*   Updated: 2024/06/08 23:49:43 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sortedcheck(t_stack *a)
{
	t_node	*now;

	now = a->rear;
	while (now->prev)
	{
		if (now->num > now->prev->num)
			now = now->prev;
		else
			return ;
	}
	destroystack(a);
	exit(0);
}
