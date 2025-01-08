/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:28:14 by djang             #+#    #+#             */
/*   Updated: 2024/06/08 18:28:17 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(1, "error\n", 6);
	exit(1);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	check_argv(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{		
			if (argv[i][j] == '+' || argv[i][j] == '-')
				j++;
			while (argv[i][j] >= '0' && argv[i][j] <= '9' || (argv[i][j] == ' '\
			&& '0' <= argv[i][j + 1] && argv[i][j + 1] <= '9'))
				j++;
			if (argv[i][j] == ' ' && \
			('+' == argv[i][j + 1] || argv[i][j + 1] == '-'))
				j += 2;
			if (argv[i][j] != '\0' && \
			!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				error();
		}
		i++;
	}
}

void	deque_in(t_stack *a, int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 0)
		{
			destroystack(a);
			error();
		}
		else
			deque_in_inner(a, argv[i]);
		i++;
	}
}

void	deque_in_inner(t_stack *a, char *str)
{
	int		i;
	int		j;
	int		len;
	long	temp;
	t_node	*num;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		j = 0;
		while (str[i] == ' ')
			i++;
		while (str[i + j] != '\0' && str[i + j] != ' ')
			j++;
		temp = ft_atoi(&str[i], j);
		num = createnode(temp);
		insertrearstack(a, num);
		if (temp > 2147483647 || temp < -2147483648)
		{
			destroystack(a);
			error();
		}
		i = i + 1 + j;
	}
}

//void	check_argv(int argc, char *argv[])
//{
//	int	i;
//	int	j;

//	i = 1;
//	while (i < argc)
//	{
//		j = 0;
//		while (argv[i][j])
//		{		
//			if (argv[i][j] == '+' || argv[i][j] == '-')
//			{
//				j++;
//				if (argv[i][j] >= '0' && argv[i][j] <= '9')
//					j++;
//				else
//					error();
//			}
//			else if ((argv[i][j] >= '0' && argv[i][j] <= '9') 
//			|| argv[i][j] == ' ')
//				j++;
//			else
//				error();
//		}
//		i++;
//	}
//}