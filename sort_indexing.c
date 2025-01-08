/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_indexing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 23:13:32 by djang             #+#    #+#             */
/*   Updated: 2024/06/10 23:13:34 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sortfor_indexing(int *array, int left, int right)
{
	int	pivot;
	int	leftpivot;
	int	rightpivot;

	if (left >= right)
		return ;
	pivot = left;
	leftpivot = left;
	rightpivot = right;
	while (leftpivot < rightpivot)
	{
		while (array[leftpivot] <= array[pivot] && leftpivot < right)
			++leftpivot;
		while (array[rightpivot] >= array[pivot] && rightpivot > left)
			--rightpivot;
		if (leftpivot < rightpivot)
			swap(&array[leftpivot], &array[rightpivot]);
	}
	swap(&array[pivot], &array[rightpivot]);
	sortfor_indexing(array, left, rightpivot - 1);
	sortfor_indexing(array, rightpivot + 1, right);
}

int	pivot(t_stack *a, int num)
{
	int		*array;
	int		pi[4];
	int		i;
	t_node	*temp;

	array = (int *)malloc(sizeof(int) * a->currentcount);
	i = 0;
	temp = a->front;
	while (i < a->currentcount)
	{
		array[i] = temp->num;
		temp = temp->next;
		i++;
	}
	sortfor_indexing(array, 0, i - 1);
	pi[0] = (array[(i - 1) / 5]);
	pi[1] = (array[((i - 1) / 5) * 2]);
	pi[2] = (array[((i - 1) / 5) * 3]);
	pi[3] = (array[((i - 1) / 5) * 4]);
	free(array);
	return (pi[num]);
}
