/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:22:12 by djang             #+#    #+#             */
/*   Updated: 2024/06/08 16:22:13 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	check_argv(argc, argv);
	a = createstack();
	deque_in(a, argc, argv);
	samecheck(a);
	sortedcheck(a);
	b = createstack();
	atob(a, b);
	destroystack(a);
	destroystack(b);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	if (s1[i] == '\n' || s1[i] == '\0')
		return (1);
	return (0);
}

/*
void	displayLinkedDeque(t_stack *pDeque)
{
	t_node	*curr;

	curr = pDeque->front;
	if (curr == NULL)
	{
		printf("empty deque\n");
		return ;
	}
	while (curr->next)
	{
		// printf("%c -> ", curr->data);
		printf("%d -> ", curr->num);
		curr = curr->next;
	}
	// printf("%c\n", curr->data);
	printf("%d\n", curr->num);
}
*/