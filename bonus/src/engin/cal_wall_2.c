/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_wall_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 02:41:25 by samin             #+#    #+#             */
/*   Updated: 2021/05/19 21:40:32 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	cal_wall_helper_7(t_info *info, t_wall_info *wall_info, int x)
{
	int y;

	y = wall_info->drawstart;
	while (y < wall_info->drawend)
	{
		wall_info->tex_y = (int)wall_info->tex_pos & (TEX_HEIGHT - 1);
		wall_info->tex_pos += wall_info->step;
		wall_info->color = info->texture[wall_info->texnum]
		[TEX_HEIGHT * wall_info->tex_y + wall_info->tex_x];
		if (wall_info->perpwalldist > 2)
			wall_info->color = (wall_info->color >> 1) & 0x787878;
		if (wall_info->perpwalldist > 4)
			wall_info->color = (wall_info->color >> 1) & 0x6e6e6e;
		if (wall_info->perpwalldist > 6)
			wall_info->color = (wall_info->color >> 1) & 0x5a5a5a;
		info->buf[y][x] = wall_info->color;
		y++;
	}
}

void	cal_wall_helper_6(t_info *info, t_wall_info *wall_info)
{
	if (wall_info->side == 0)
	{
		wall_info->wall_x =
		info->pos_y + wall_info->perpwalldist * wall_info->raydir_y;
	}
	else
	{
		wall_info->wall_x =
		info->pos_x + wall_info->perpwalldist * wall_info->raydir_x;
	}
	wall_info->wall_x -= floor((wall_info->wall_x));
	wall_info->tex_x = (int)(wall_info->wall_x * (double)TEX_WIDTH);
	if (wall_info->side == 0 && wall_info->raydir_x > 0)
		wall_info->tex_x = TEX_WIDTH - wall_info->tex_x - 1;
	if (wall_info->side == 1 && wall_info->raydir_y < 0)
		wall_info->tex_x = TEX_WIDTH - wall_info->tex_x - 1;
	wall_info->step = 1.0 * TEX_HEIGHT / wall_info->lineheight;
	wall_info->tex_pos =
	(wall_info->drawstart - info->height / 2 + wall_info->lineheight / 2)
	* wall_info->step;
}

void	cal_wall_helper_5(t_wall_info *wall_info)
{
	if (wall_info->side == 0 && wall_info->step_x == -1)
		wall_info->texnum = 0;
	else if (wall_info->side == 0 && wall_info->step_x == 1)
		wall_info->texnum = 1;
	else if (wall_info->side == 1 && wall_info->step_y == -1)
		wall_info->texnum = 2;
	else if (wall_info->side == 1 && wall_info->step_y == 1)
		wall_info->texnum = 3;
}

void	cal_wall_helper_4(t_info *info, t_wall_info *wall_info)
{
	if (wall_info->side == 0)
	{
		wall_info->perpwalldist =
		(wall_info->map_x - info->pos_x +
		(1 - wall_info->step_x) / 2) / wall_info->raydir_x;
	}
	else
	{
		wall_info->perpwalldist =
		(wall_info->map_y - info->pos_y +
		(1 - wall_info->step_y) / 2) / wall_info->raydir_y;
	}
	wall_info->lineheight = (int)(info->height / wall_info->perpwalldist);
	wall_info->drawstart = -(wall_info->lineheight) / 2 + info->height / 2;
	if (wall_info->drawstart < 0)
		wall_info->drawstart = 0;
	wall_info->drawend = wall_info->lineheight / 2 + info->height / 2;
	if (wall_info->drawend >= info->height)
		wall_info->drawend = info->height - 1;
}
