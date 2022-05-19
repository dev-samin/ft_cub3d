/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:58:31 by samin             #+#    #+#             */
/*   Updated: 2021/05/19 21:02:26 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	cal_wall_helper_3(t_info *info, t_wall_info *wall_info)
{
	while (wall_info->hit == 0)
	{
		if (wall_info->sidedist_x < wall_info->sidedist_y)
		{
			wall_info->sidedist_x += wall_info->deltadist_x;
			wall_info->map_x += wall_info->step_x;
			wall_info->side = 0;
		}
		else
		{
			wall_info->sidedist_y += wall_info->deltadist_y;
			wall_info->map_y += wall_info->step_y;
			wall_info->side = 1;
		}
		if (info->worldmap[wall_info->map_x][wall_info->map_y] == '1')
			wall_info->hit = 1;
	}
}

void	cal_wall_helper_2(t_info *info, t_wall_info *wall_info)
{
	if (wall_info->raydir_x < 0)
	{
		wall_info->step_x = -1;
		wall_info->sidedist_x =
		(info->pos_x - wall_info->map_x) * wall_info->deltadist_x;
	}
	else
	{
		wall_info->step_x = 1;
		wall_info->sidedist_x =
		(wall_info->map_x + 1.0 - info->pos_x) * wall_info->deltadist_x;
	}
	if (wall_info->raydir_y < 0)
	{
		wall_info->step_y = -1;
		wall_info->sidedist_y =
		(info->pos_y - wall_info->map_y) * wall_info->deltadist_y;
	}
	else
	{
		wall_info->step_y = 1;
		wall_info->sidedist_y =
		(wall_info->map_y + 1.0 - info->pos_y) * wall_info->deltadist_y;
	}
}

void	cal_wall_helper_1(t_info *info, t_wall_info *wall_info, int x)
{
	wall_info->camera_x = 2 * x / (double)info->width - 1;
	wall_info->raydir_x = info->dir_x + info->plane_x * wall_info->camera_x;
	wall_info->raydir_y = info->dir_y + info->plane_y * wall_info->camera_x;
	wall_info->map_x = (int)info->pos_x;
	wall_info->map_y = (int)info->pos_y;
	wall_info->sidedist_x = 0;
	wall_info->sidedist_x = 0;
	wall_info->deltadist_x = fabs(1 / wall_info->raydir_x);
	wall_info->deltadist_y = fabs(1 / wall_info->raydir_y);
	wall_info->hit = 0;
	wall_info->side = 0;
}

void	cal_wall(t_info *info)
{
	t_wall_info wall_info;
	int			x;
	int			y;

	x = 0;
	while (x < info->width)
	{
		cal_wall_helper_1(info, &wall_info, x);
		cal_wall_helper_2(info, &wall_info);
		cal_wall_helper_3(info, &wall_info);
		cal_wall_helper_4(info, &wall_info);
		cal_wall_helper_5(&wall_info);
		cal_wall_helper_6(info, &wall_info);
		cal_wall_helper_7(info, &wall_info, x);
		info->zbuffer[x] = wall_info.perpwalldist;
		x++;
	}
}
