/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_option_resolution.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 22:29:27 by samin             #+#    #+#             */
/*   Updated: 2021/05/14 00:53:41 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	parse_helper_resolution(t_option *op, char *line)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	tmp = ft_split(line, ' ');
	if (tmp[1] == 0 || tmp[2] == 0)
		custom_error("not enough resolution value error");
	if (tmp[3] != 0)
		custom_error("too many resolution value error");
	while (++i < 3)
	{
		j = -1;
		while (++j < (int)ft_strlen(tmp[i]))
		{
			if (ft_isdigit((int)tmp[i][j]) == 0)
				custom_error("unnumeric resolution value error");
		}
	}
	op->r[0] = ft_atoi(tmp[1]);
	op->r[1] = ft_atoi(tmp[2]);
	i = -1;
	while (++i < 3)
		free(tmp[i]);
	free(tmp);
}

void	parse_resolution(t_option *op, char *line)
{
	if (ft_strncmp(line, "R ", 2) == 0)
	{
		if (op->checker[0] == 0)
		{
			parse_helper_resolution(op, line);
			op->checker[0]++;
		}
		else
			custom_error("resolution error");
	}
}
