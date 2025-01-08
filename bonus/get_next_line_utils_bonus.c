/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:56:26 by djang             #+#    #+#             */
/*   Updated: 2024/06/14 21:00:08 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_strdup(const char *str)
{
	char	*dest;
	int		len;
	char	*temp;

	len = 0;
	while (str[len])
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	temp = dest;
	while (*str)
	{
		*dest = *str;
		dest++;
		str++;
	}
	*dest = '\0';
	return (temp);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return ((char *)str + i);
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*temp;
	const char		*s;
	size_t			i;

	if (n == 0 || dest == src)
		return (dest);
	if (dest == NULL && src == NULL)
		return (NULL);
	temp = dest;
	s = src;
	i = 0;
	while (i < n)
	{
		temp[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*temp;

	i = ft_strlen((char *)s1);
	j = ft_strlen((char *)s2);
	temp = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!temp)
		return (0);
	ft_memcpy(temp, s1, i);
	ft_memcpy(temp + i, s2, j);
	temp[i + j] = '\0';
	return (temp);
}
