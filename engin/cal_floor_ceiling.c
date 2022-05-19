/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_floor_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 01:39:28 by samin             #+#    #+#             */
/*   Updated: 2021/05/13 19:46:52 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	cal_floor_ceiling(t_info *info)
{
	int x;
	int y;

	x = 0;
	while (x < info->width)
	{
		y = 0;
		while (y < info->height)
		{
			info->buf[y][x] = info->f_rgb;
			info->buf[info->height - y - 1][x] = info->c_rgb;
			y++;
		}
		x++;
	}
}
