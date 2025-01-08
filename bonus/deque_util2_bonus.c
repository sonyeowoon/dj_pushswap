/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_util2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:51:15 by djang             #+#    #+#             */
/*   Updated: 2024/06/18 18:50:31 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	insertfrontstack(t_stack *stack, t_node *element)
{
	if (isstackempty(stack) == 1)
	{
		element->prev = NULL;
		element->next = NULL;
		stack->front = element;
		stack->rear = element;
	}
	else
	{
		element->prev = NULL;
		element->next = stack->front;
		stack->front->prev = element;
		stack->front = element;
	}
	stack->currentcount++;
}

void	insertrearstack(t_stack *stack, t_node *element)
{
	if (isstackempty(stack) == 1)
	{
		element->prev = NULL;
		element->next = NULL;
		stack->front = element;
		stack->rear = element;
	}
	else
	{
		element->next = NULL;
		element->prev = stack->rear;
		stack->rear->next = element;
		stack->rear = element;
	}
	stack->currentcount++;
}

t_node	*deletefrontstack(t_stack *stack)
{
	t_node	*temp;

	temp = peekfrontstack(stack);
	if (temp == NULL)
		return (NULL);
	if (stack->currentcount == 1)
	{
		stack->front = NULL;
		stack->rear = NULL;
	}
	else
	{
		stack->front = temp->next;
		stack->front->prev = NULL;
	}
	temp->next = NULL;
	stack->currentcount--;
	return (temp);
}

t_node	*deleterearstack(t_stack *stack)
{
	t_node	*temp;

	temp = peekrearstack(stack);
	if (temp == NULL)
		return (NULL);
	if (stack->currentcount == 1)
	{
		stack->front = NULL;
		stack->rear = NULL;
	}
	else
	{
		stack->rear = temp->prev;
		stack->rear->next = NULL;
	}
	temp->prev = NULL;
	stack->currentcount--;
	return (temp);
}

void	destroystack(t_stack *stack)
{
	t_node	*curr;
	t_node	*next;

	curr = stack->front;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	free(stack);
}
