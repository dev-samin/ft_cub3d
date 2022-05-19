/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_option_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 22:30:32 by samin             #+#    #+#             */
/*   Updated: 2021/05/13 19:46:02 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	parse_texture(t_option *op, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		parse_helper_texture(&(op->no), line, "NO ");
		op->checker[1]++;
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		parse_helper_texture(&(op->so), line, "SO ");
		op->checker[2]++;
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		parse_helper_texture(&(op->we), line, "WE ");
		op->checker[3]++;
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		parse_helper_texture(&(op->ea), line, "EA ");
		op->checker[4]++;
	}
	else if (ft_strncmp(line, "S ", 2) == 0)
	{
		parse_helper_texture(&(op->s), line, "S ");
		op->checker[5]++;
	}
}

void	parse_helper_texture(char **texture, char *line, char *op_spec)
{
	int op_spec_len;
	int fd;

	op_spec_len = (int)ft_strlen(op_spec);
	while (line[op_spec_len] == ' ')
		op_spec_len++;
	check_format(line + op_spec_len, ".xpm");
	if (*texture == 0)
		*texture = ft_strdup(line + op_spec_len);
	else
		custom_error("texture error");
	if ((fd = open(*texture, O_RDONLY)) == -1)
		custom_error("texture file error");
}
