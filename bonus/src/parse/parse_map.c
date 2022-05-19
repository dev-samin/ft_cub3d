/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 02:47:47 by samin             #+#    #+#             */
/*   Updated: 2021/05/13 19:46:10 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	join_map(t_option *op, char *line, char **buff)
{
	char	*tmp_buff;
	int		tmp;

	tmp = 0;
	tmp_buff = ft_strjoin(*buff, line);
	free(*buff);
	*buff = ft_strdup(tmp_buff);
	free(tmp_buff);
	tmp_buff = ft_strjoin(*buff, "\n");
	free(*buff);
	*buff = ft_strdup(tmp_buff);
	free(tmp_buff);
	tmp = ft_strlen(line);
	if (op->map_x < tmp)
		op->map_x = tmp;
	op->map_y++;
}

void	create_empty_map(t_option *op, char **tmp_map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	op->map = (char**)malloc(sizeof(char**) * op->map_y);
	while (i < op->map_y)
	{
		op->map[i] = (char *)ft_calloc(op->map_x, sizeof(char*));
		i++;
	}
	i = 0;
	while (i < op->map_y)
	{
		while (j < (int)ft_strlen(tmp_map[i]))
		{
			op->map[i][j] = tmp_map[i][j];
			j++;
		}
		free(tmp_map[i]);
		j = 0;
		i++;
	}
	free(tmp_map);
}

void	parse_map(t_option *op, char *line, char **buff)
{
	is_option_full(op);
	if (line[0] == 0)
		op->empty_line = 1;
	if (op->empty_line == 1 && is_map(line) == 1)
		custom_error("empty space map error");
	if (line[0] != 0 && is_map(line) == 0)
		custom_error("Invalid map error");
	if (line[0] != 0)
		join_map(op, line, buff);
}
