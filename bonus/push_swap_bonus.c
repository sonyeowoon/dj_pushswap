/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:09:52 by djang             #+#    #+#             */
/*   Updated: 2024/06/14 19:56:46 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	b = createstack();
	check(a, b);
	sortedcheck(a, b);
	destroystack(a);
	destroystack(b);
}
