/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btoa_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:32:13 by djang             #+#    #+#             */
/*   Updated: 2024/06/14 15:32:14 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	maxormin(t_stack *a, int min)
{
	int		a_index;
	t_node	*now;

	now = a->front;
	a_index = 0;
	while (now->num != min)
	{
		now = now->next;
		a_index++;
	}
	if (a_index > (a->currentcount) / 2)
		return ((a->currentcount - a_index) * -1);
	return (a_index);
}

int	count_ra(t_stack *a, int num)
{
	int		min;
	int		max;
	int		a_index;
	t_node	*now;

	a_index = 1;
	now = a->front;
	max = get_max(a);
	min = get_min(a);
	if (num > max || num < min)
		return (maxormin(a, min));
	if (a->front->num > num && a->rear->num < num)
		return (0);
	while (1)
	{
		if (now->num < num && now->next->num > num)
		{
			if (a_index > (a->currentcount) / 2)
				return ((a->currentcount - a_index) * -1);
			return (a_index);
		}
		now = now->next;
		a_index++;
	}
}

int	indicator(int ra_count, int rb_count, int new_ra_count, int new_rb_count)
{
	int	old;
	int	new;

	old = cal(ra_count, rb_count);
	new = cal(new_ra_count, new_rb_count);
	if (new < old)
		return (1);
	else
		return (0);
}

int	cal(int ra, int rb)
{
	int	counter_minus_ra;
	int	counter_minus_rb;

	counter_minus_ra = 1;
	counter_minus_rb = 1;
	if (ra < 0)
		counter_minus_ra = -1;
	if (rb < 0)
		counter_minus_rb = -1;
	if (counter_minus_ra * counter_minus_rb == -1)
		return (ra * counter_minus_ra + rb * counter_minus_rb);
	else if (ra * counter_minus_ra < rb * counter_minus_rb)
		return (rb * counter_minus_rb);
	else
		return (ra * counter_minus_ra);
}

void	count(t_stack *a, t_stack *b, int *ra_count, int *rb_count)
{
	t_node	*now;
	int		new_ra_count;
	int		new_rb_count;
	int		b_index;

	now = b->front;
	b_index = 0;
	while (b_index < b->currentcount)
	{
		new_ra_count = count_ra(a, now->num);
		if (b_index > (b->currentcount) / 2)
			new_rb_count = (b->currentcount - b_index) * -1;
		else
			new_rb_count = b_index;
		if (b_index == 0 || \
		indicator(*ra_count, *rb_count, new_ra_count, new_rb_count))
		{
			*ra_count = new_ra_count;
			*rb_count = new_rb_count;
		}
		now = now->next;
		b_index++;
	}
}
