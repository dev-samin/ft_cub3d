/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 23:21:52 by samin             #+#    #+#             */
/*   Updated: 2021/05/19 21:12:53 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	check_argc(t_info *info, int argc, char **argv)
{
	if (!(argc == 2 || argc == 3))
		custom_error("argc error");
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 6) == 0)
			info->save_sw = 1;
		else
			custom_error("argc error");
	}
}

void	check_format(char *str1, char *str2)
{
	int str1len;
	int str2len;

	str1len = ft_strlen(str1);
	str2len = ft_strlen(str2);
	if (ft_strncmp((str1 + str1len - str2len), str2, str2len) != 0)
		custom_error("format error");
	return ;
}

void	parser(int fd, t_option *op)
{
	char	*line;
	char	*buff;
	char	**tmp_map;
	int		i;

	i = 0;
	buff = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (op->map_sw == 0)
			op->map_sw = is_map(line);
		if (op->map_sw == 0)
			parse_option(op, line);
		else
			parse_map(op, line, &buff);
		free(line);
	}
	if (line[0] != 0)
		parse_map(op, line, &buff);
	free(line);
	tmp_map = ft_split(buff, '\n');
	free(buff);
	create_empty_map(op, tmp_map);
}

void	parse_cub3d(char **argv, t_option *op)
{
	int fd;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		custom_error("file open error");
	parser(fd, op);
	close(fd);
}
