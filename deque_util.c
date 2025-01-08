/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:27:19 by djang             #+#    #+#             */
/*   Updated: 2024/06/08 15:27:21 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*createstack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->currentcount = 0;
	stack->front = NULL;
	stack->rear = NULL;
	return (stack);
}

t_node	*createnode(int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->num = data;
	return (new);
}

int	isstackempty(t_stack *stack)
{
	return (stack->currentcount == 0);
}

t_node	*peekfrontstack(t_stack *stack)
{
	if (isstackempty(stack) == 1)
		return (NULL);
	return (stack->front);
}

t_node	*peekrearstack(t_stack *stack)
{
	if (isstackempty(stack) == 1)
		return (NULL);
	return (stack->rear);
}
