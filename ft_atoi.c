/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:32:10 by djang             #+#    #+#             */
/*   Updated: 2024/06/08 16:32:11 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *str, int end)
{
	long long	intnum;
	int			countminus;

	countminus = 1;
	intnum = 0;
	str[end] = '\0';
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			countminus = countminus * -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		intnum = intnum * 10 + (*str - 48);
		str++;
	}
	return (intnum * countminus);
}
