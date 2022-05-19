/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_option_rgb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 22:31:30 by samin             #+#    #+#             */
/*   Updated: 2021/05/19 22:11:06 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	parse_helper_rgb2(char **tmp)
{
	int		i;
	int		j;
	char	*trimed_tmp;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < (int)ft_strlen(tmp[i]))
		{
			trimed_tmp = ft_strtrim(tmp[i], " ");
			free(tmp[i]);
			tmp[i] = trimed_tmp;
			if (ft_isdigit((int)tmp[i][j]) == 0)
				custom_error("unnumeric RGB value error");
		}
	}
}

void	parse_helper_rgb1(int *rgb, char *line)
{
	char	**tmp;
	int		i;

	i = 0;
	parse_helper_rgb0(line);
	while (line[i + 1] == ' ')
		i++;
	tmp = ft_split(line + i + 1, ',');
	if (tmp[0] == NULL || tmp[1] == NULL || tmp[2] == NULL)
		custom_error("not enough RGB value error");
	if (tmp[3] != 0)
		custom_error("too many RGB value error");
	parse_helper_rgb2(tmp);
	i = -1;
	while (++i < 3)
	{
		rgb[i] = ft_atoi(tmp[i]);
		free(tmp[i]);
		if (rgb[i] > 255 || rgb[i] < 0)
			custom_error("over range RGB value error");
	}
	free(tmp);
}

void	parse_helper_rgb0(char *line)
{
	int		i;
	int		cnt;
	int		line_len;

	i = -1;
	cnt = 0;
	line_len = (int)ft_strlen(line);
	while (++i < line_len)
	{
		if (line[i] == ',')
			cnt++;
	}
	if (cnt != 2)
		custom_error("RGB value error");
}

void	parse_rgb(t_option *op, char *line)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (op->checker[6] == 0)
		{
			parse_helper_rgb1(op->f, line);
			op->checker[6]++;
		}
		else
			custom_error("overlaped RGB value error");
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (op->checker[7] == 0)
		{
			parse_helper_rgb1(op->c, line);
			op->checker[7]++;
		}
		else
			custom_error("overlaped RGB value error");
	}
}
