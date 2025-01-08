/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:02:18 by djang             #+#    #+#             */
/*   Updated: 2024/06/11 14:02:20 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	atob(t_stack *a, t_stack *b)
{
	if (a->currentcount >= 100)
		divide_move(a, b);
	else if (a->currentcount < 100 && a->currentcount > 10)
		divide_move2(a, b);
	while (a->currentcount > 3)
		pb(b, a);
	hard_sorting(a);
	while (b->currentcount)
		btoa(a, b);
	last(a);
	return ;
}
