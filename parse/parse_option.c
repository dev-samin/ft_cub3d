/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 02:47:49 by samin             #+#    #+#             */
/*   Updated: 2021/05/14 00:53:27 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	parse_option(t_option *op, char *line)
{
	if ((ft_strncmp(line, "R ", 2) == 0) ||
	(ft_strncmp(line, "NO ", 3) == 0) ||
	(ft_strncmp(line, "SO ", 3) == 0) ||
	(ft_strncmp(line, "WE ", 3) == 0) ||
	(ft_strncmp(line, "EA ", 3) == 0) ||
	(ft_strncmp(line, "S ", 2) == 0) ||
	(ft_strncmp(line, "F ", 2) == 0) ||
	(ft_strncmp(line, "C ", 2) == 0) ||
	line[0] == 0)
	{
		parse_resolution(op, line);
		parse_texture(op, line);
		parse_rgb(op, line);
	}
	else
		custom_error("other than option values error");
}
