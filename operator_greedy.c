/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_greedy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:33:28 by djang             #+#    #+#             */
/*   Updated: 2024/06/12 01:33:30 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rr_rrr(t_stack *a, t_stack *b, int *ra_count, int *rb_count)
{
	while (*ra_count > 0 && *rb_count > 0)
	{
		rr(a, b);
		*ra_count -= 1;
		*rb_count -= 1;
	}
	while (*ra_count < 0 && *rb_count < 0)
	{
		rrr(a, b);
		*ra_count += 1;
		*rb_count += 1;
	}
}

void	do_ra_rra(t_stack *a, int *ra_count)
{
	while (*ra_count)
	{
		if (*ra_count > 0)
		{
			ra(a);
			*ra_count -= 1;
		}
		else
		{
			rra(a);
			*ra_count += 1;
		}
	}
}

void	do_rb_rrb(t_stack *b, int *rb_count)
{
	while (*rb_count)
	{
		if (*rb_count > 0)
		{
			rb(b);
			*rb_count -= 1;
		}
		else
		{
			rrb(b);
			*rb_count += 1;
		}
	}
}

void	last(t_stack *a)
{
	int		min;
	int		a_index;
	t_node	*now;

	a_index = 0;
	now = a->front;
	min = get_min(a);
	while (now->num != min)
	{
		now = now->next;
		a_index++;
	}
	if (a_index > a->currentcount / 2)
	{
		a_index = a->currentcount - a_index;
		while (a_index--)
			rra(a);
	}
	else
	{
		while (a_index--)
			ra(a);
	}
}
