/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:45:06 by djang             #+#    #+#             */
/*   Updated: 2024/06/14 20:45:07 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	check(t_stack *a, t_stack *b)
{
	char	*temp;

	while (1)
	{
		temp = get_next_line(0);
		if (temp == NULL)
			break ;
		check_inner(a, b, temp);
		free(temp);
	}
}

void	check_inner(t_stack *a, t_stack *b, char *temp)
{
	if (ft_strcmp(temp, "sa"))
		sa(a);
	else if (ft_strcmp(temp, "sb"))
		sb(b);
	else if (ft_strcmp(temp, "ss"))
		ss(a, b);
	else if (ft_strcmp(temp, "pa"))
		pa(a, b);
	else if (ft_strcmp(temp, "pb"))
		pb(b, a);
	else if (ft_strcmp(temp, "ra"))
		ra(a);
	else if (ft_strcmp(temp, "rb"))
		rb(b);
	else if (ft_strcmp(temp, "rr"))
		rr(a, b);
	else if (ft_strcmp(temp, "rra"))
		rra(a);
	else if (ft_strcmp(temp, "rrb"))
		rrb(b);
	else if (ft_strcmp(temp, "rrr"))
		rrr(a, b);
	else
		checker_error_exit(a, b, temp);
}

void	checker_error_exit(t_stack *a, t_stack *b, char *temp)
{
	destroystack(a);
	destroystack(b);
	free(temp);
	error();
}
