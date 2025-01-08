/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:18:35 by djang             #+#    #+#             */
/*   Updated: 2024/06/11 15:18:36 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *a)
{
	int		min;
	t_node	*temp;

	temp = a->front;
	min = temp->num;
	while (temp)
	{
		if (temp->num < min)
			min = temp->num;
		temp = temp->next;
	}
	return (min);
}

int	get_max(t_stack *a)
{
	int		max;
	t_node	*temp;

	temp = a->front;
	max = temp->num;
	while (temp)
	{
		if (temp->num > max)
			max = temp->num;
		temp = temp->next;
	}
	return (max);
}
