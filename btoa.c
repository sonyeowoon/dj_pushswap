/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:29:16 by djang             #+#    #+#             */
/*   Updated: 2024/06/11 19:29:18 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	btoa(t_stack *a, t_stack *b)
{
	int	ra_count;
	int	rb_count;

	ra_count = 0;
	rb_count = 0;
	count(a, b, &ra_count, &rb_count);
	do_rr_rrr(a, b, &ra_count, &rb_count);
	do_ra_rra(a, &ra_count);
	do_rb_rrb(b, &rb_count);
	pa(a, b);
}
