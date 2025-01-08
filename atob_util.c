/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:31:59 by djang             #+#    #+#             */
/*   Updated: 2024/06/14 15:32:02 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_move(t_stack *a, t_stack *b)
{
	int	point[4];
	int	aszie;

	aszie = a->currentcount;
	point[0] = pivot(a, 0);
	point[1] = pivot(a, 1);
	point[2] = pivot(a, 2);
	point[3] = pivot(a, 3);
	while (aszie)
	{
		if (a->front->num > point[2] || a->front->num <= point[0])
			ra(a);
		else if (a->front->num > point[0] && a->front->num <= point[2])
		{
			pb(b, a);
			if (b->front->num > point[0] && b->front->num <= point[1])
				rb(b);
		}
		aszie--;
	}
	divide_move_inner(a, b, point[0], point[3]);
}

void	divide_move_inner(t_stack *a, t_stack *b, int p0, int p3)
{
	int	aszie;

	aszie = a->currentcount;
	while (aszie)
	{
		if (a->front->num > p3)
			ra(a);
		else
		{
			pb(b, a);
			if (b->front->num <= p0)
				rb(b);
		}
		aszie--;
	}
}

void	divide_move2(t_stack *a, t_stack *b)
{
	int	asize;
	int	p1;
	int	p2;

	asize = a->currentcount;
	p1 = (get_min(a) + get_max(a)) / 3;
	p2 = p1 * 2;
	while (asize)
	{
		if (a->front->num > p2)
			ra(a);
		else
		{
			pb(b, a);
			if (b->front->num < p1)
				rb(b);
		}
		asize--;
	}
}

void	hard_sorting(t_stack *a)
{
	if (a->currentcount <= 1)
		return ;
	else if (a->currentcount == 2)
	{
		if (a->front->num > a->front->next->num)
			sa(a);
	}		
	else
		sorting_three(a);
}

void	sorting_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->front->num;
	second = a->front->next->num;
	third = a->rear->num;
	if (first < second && first < third && second > third)
	{
		rra(a);
		sa(a);
	}
	else if (first > second && first < third && second < third)
		sa(a);
	else if (first < second && first > third && second > third)
		rra(a);
	else if (first > second && first > third && second < third)
		ra(a);
	else if (first > second && first > third && second > third)
	{
		ra(a);
		sa(a);
	}
	else
		return ;
}
