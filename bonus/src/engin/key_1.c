/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:46:25 by samin             #+#    #+#             */
/*   Updated: 2021/05/14 03:56:52 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	key_update_helper_moving2(t_info *info)
{
	if (info->key_a && info->key_d)
		return ;
	if (info->key_a)
	{
		if (info->worldmap[(int)(info->pos_x - info->plane_x * info->movespeed)]
		[(int)(info->pos_y)] != '1')
			info->pos_x -= info->plane_x * info->movespeed;
		if (info->worldmap[(int)(info->pos_x)]
		[(int)(info->pos_y - info->plane_y * info->movespeed)] != '1')
			info->pos_y -= info->plane_y * info->movespeed;
	}
	else if (info->key_d)
	{
		if (info->worldmap[(int)(info->pos_x + info->plane_x * info->movespeed)]
		[(int)(info->pos_y)] != '1')
			info->pos_x += info->plane_x * info->movespeed;
		if (info->worldmap[(int)(info->pos_x)]
		[(int)(info->pos_y + info->plane_y * info->movespeed)] != '1')
			info->pos_y += info->plane_y * info->movespeed;
	}
}

void	key_update_helper_moving1(t_info *info)
{
	if (info->key_w && info->key_s)
		return ;
	if (info->key_w)
	{
		if (info->worldmap[(int)(info->pos_x + info->dir_x * info->movespeed)]
		[(int)(info->pos_y)] != '1')
			info->pos_x += info->dir_x * info->movespeed;
		if (info->worldmap[(int)(info->pos_x)]
		[(int)(info->pos_y + info->dir_y * info->movespeed)] != '1')
			info->pos_y += info->dir_y * info->movespeed;
	}
	else if (info->key_s)
	{
		if (info->worldmap[(int)(info->pos_x - info->dir_x * info->movespeed)]
		[(int)(info->pos_y)] != '1')
			info->pos_x -= info->dir_x * info->movespeed;
		if (info->worldmap[(int)(info->pos_x)]
		[(int)(info->pos_y - info->dir_y * info->movespeed)] != '1')
			info->pos_y -= info->dir_y * info->movespeed;
	}
}

void	key_update_helper_rotate2(t_info *info)
{
	if (info->key_right && info->key_left)
		return ;
	if (info->key_right)
	{
		info->dir_x = info->dir_x *
		cos(-info->rotspeed) - info->dir_y * sin(-info->rotspeed);
		info->dir_y = info->old_dir_x *
		sin(-info->rotspeed) + info->dir_y * cos(-info->rotspeed);
		info->plane_x = info->plane_x *
		cos(-info->rotspeed) - info->plane_y * sin(-info->rotspeed);
		info->plane_y = info->old_plane_x *
		sin(-info->rotspeed) + info->plane_y * cos(-info->rotspeed);
	}
	else if (info->key_left && !(info->key_right && info->key_left))
	{
		info->dir_x = info->dir_x *
		cos(info->rotspeed) - info->dir_y * sin(info->rotspeed);
		info->dir_y = info->old_dir_x *
		sin(info->rotspeed) + info->dir_y * cos(info->rotspeed);
		info->plane_x = info->plane_x *
		cos(info->rotspeed) - info->plane_y * sin(info->rotspeed);
		info->plane_y = info->old_plane_x *
		sin(info->rotspeed) + info->plane_y * cos(info->rotspeed);
	}
}

void	key_update_helper_rotate1(t_info *info)
{
	info->old_dir_x = info->dir_x;
	info->old_plane_x = info->plane_x;
	key_update_helper_rotate2(info);
}

void	key_update(t_info *info)
{
	key_update_helper_moving1(info);
	key_update_helper_moving2(info);
	key_update_helper_rotate1(info);
	if (info->key_esc)
		exit(0);
}
