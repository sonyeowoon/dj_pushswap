/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:56:07 by djang             #+#    #+#             */
/*   Updated: 2024/06/14 20:59:54 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*restore_value(char *backup)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	if (backup[i] == '\0' || backup[i] == '\n')
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	j = 0;
	while (backup[i] != '\0')
		temp[j++] = backup[i++];
	temp[j] = '\0';
	free(backup);
	return (temp);
}

char	*returning_value(char *backup)
{
	char	*temp;
	int		i;

	i = 0;
	if (!backup[i])
		return (NULL);
	while (backup[i] != '\0' && backup[i] != '\n')
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (NULL);
	i = 0;
	while (backup[i] != '\0' && backup[i] != '\n')
	{
		temp[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		temp[i] = backup[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*get_next_line_inner(int fd, char *buffer, char *backup)
{
	int		n;
	char	*temp;

	n = 1;
	while (n != 0 && ft_strchr(backup, '\n') == 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
		{
			free(buffer);
			free(backup);
			return (NULL);
		}
		buffer[n] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(backup, buffer);
		free(temp);
	}
	free(buffer);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!backup)
		backup = ft_strdup("");
	backup = get_next_line_inner(fd, buffer, backup);
	if (!backup)
		return (NULL);
	line = returning_value(backup);
	backup = restore_value(backup);
	if (line == NULL)
		return (NULL);
	return (line);
}
