/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:58:28 by samin             #+#    #+#             */
/*   Updated: 2021/05/14 01:24:01 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		is_map(char *line)
{
	int i;
	int check;

	i = 0;
	check = 0;
	while (i < (int)ft_strlen(line))
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == '2'
		|| line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
		|| line[i] == 'E' || line[i] == ' ')
			check = 1;
		else
		{
			check = 0;
			break ;
		}
		i++;
	}
	return (check);
}

void	is_option_full(t_option *op)
{
	if (op->checker[0] == 0 || op->checker[1] == 0
	|| op->checker[2] == 0 || op->checker[3] == 0
	|| op->checker[4] == 0 || op->checker[5] == 0
	|| op->checker[6] == 0 || op->checker[7] == 0)
		custom_error("not enough ottion value");
}

void	dfs_map(t_option *op, char **map, int y, int x)
{
	if (x == 0 || x == op->map_x - 1
	|| y == 0 || y == op->map_y - 1
	|| map[y][x] == ' ' || map[y][x] == 0)
		custom_error("Invalid map error");
	if (map[y][x] != '1')
		map[y][x] = 'V';
	if (y < op->map_y - 1 &&
	(map[y + 1][x] == '0' || map[y + 1][x] == ' ' || map[y + 1][x] == 0))
		dfs_map(op, map, y + 1, x);
	if (y > 0 &&
	(map[y - 1][x] == '0' || map[y - 1][x] == ' ' || map[y - 1][x] == 0))
		dfs_map(op, map, y - 1, x);
	if (x < op->map_x - 1 &&
	(map[y][x + 1] == '0' || map[y][x + 1] == ' ' || map[y][x + 1] == 0))
		dfs_map(op, map, y, x + 1);
	if (x > 0 &&
	(map[y][x - 1] == '0' || map[y][x - 1] == ' ' || map[y][x + 1] == 0))
		dfs_map(op, map, y, x - 1);
}
