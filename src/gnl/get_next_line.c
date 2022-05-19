/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 10:22:08 by samin             #+#    #+#             */
/*   Updated: 2021/04/17 22:54:41 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		n_finder(char *buff)
{
	int i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		buff_divider(char **line, char **backup, int n_index)
{
	char *tmp;

	if ((n_index = n_finder(*backup)) != -1)
	{
		*line = ft_substr(*backup, 0, n_index);
		tmp = ft_strdup(&(*backup)[n_index + 1]);
		free(*backup);
		*backup = tmp;
	}
	else
	{
		*line = ft_strdup(*backup);
		free(*backup);
		*backup = NULL;
		return (0);
	}
	return (1);
}

int		buff_empty_checker(
	char **line, char **backup, int read_size, int n_index)
{
	if (read_size < 0)
		return (-1);
	else if (read_size == 0 && *backup == NULL)
	{
		*line = ft_strdup("");
		free(*backup);
		*backup = NULL;
		return (0);
	}
	else
		return (buff_divider(line, &(*backup), n_index));
}

int		get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char *backup[OPEN_MAX];
	char		*tmp;
	int			read_size;
	int			n_index;

	if (fd < 0 || fd > OPEN_MAX || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((read_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[read_size] = '\0';
		if (backup[fd] == NULL)
			backup[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(backup[fd], buff);
			free(backup[fd]);
			backup[fd] = ft_strdup(tmp);
			free(tmp);
		}
		if ((n_index = (n_finder(backup[fd]))) != -1)
			break ;
	}
	return (buff_empty_checker(line, &backup[fd], read_size, n_index));
}
